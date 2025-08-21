/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:34:08 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/21 10:24:29 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

char	*ft_copytab(char **map)
{
	int		fd;
	char	*tmp;
	char	*gnl;
	char	*tab;

	tmp = NULL;
	tab = NULL;
	fd = open(map[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = ft_calloc(1, 1);
	if (!tab)
		return (NULL);
	gnl = get_next_line(fd);
	while (gnl != 0)
	{
		tmp = ft_strjoin(tab, gnl);
		free(tab);
		free(gnl);
		tab = tmp;
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (tab);
}

int	ft_map_tab(t_cub *cub, char *tab)
{
	if (!tab)
		return (1);
	cub->map->size_ver = 0;
	cub->map->size_ver = ft_strlen_map(tab);
	cub->map->map = ft_calloc(cub->map->size_ver + 1, sizeof(char *));
	if (!cub->map->map)
	{
		free(tab);
		return (1);
	}
	if (ft_transfer_map(cub, tab) == 1)
	{
		free(tab);
		return (1);
	}
	return (0);
}

int	verif_character_map(char **map_tmp, t_cub *cub)
{
	int		x;
	int		y;
	char	*txt;
	char	*txt2;

	y = 0;
	cub->map->nb_player = 0;
	txt = "Error\nThe characters to create the map are not compliant\n";
	txt2 = "Error\nMap too big\n";
	while (map_tmp[y])
	{
		x = 0;
		while (map_tmp[y][x])
		{
			if (x > 150 || y > 150)
			{
				write (2, txt2, 17);
				return (1);
			}
			if (ft_charac_accetable(map_tmp[y][x], cub, x, y) == 1)
			{
				write (2, txt, 58);
				return (1);
			}
			x++;
		}
		y++;
	}
	if (ft_error_charac(cub) == 1)
		return (1);
	return (0);
}

void	ft_new_map(t_cub *cub, char **map_tmp, int count)
{
	int	j;

	j = 0;
	ft_free(cub->map->map);
	cub->map->size_ver = cub->map->size_ver - count;
	cub->map->map = ft_calloc(cub->map->size_ver + 1, sizeof(char *));
	if (!cub->map->map)
	{
		free_all(cub);
		exit (1);
	}
	while (map_tmp && map_tmp[count])
	{
		cub->map->map[j] = ft_strdup(map_tmp[count]);
		j++;
		count++;
	}
	ft_free(map_tmp);
}

int	ft_parsing(char **map, t_cub *cub)
{
	char	*tab;
	char	**map_tmp;

	tab = ft_copytab(map);
	if (ft_map_tab(cub, tab))
		return (1);
	only_map(cub);
	map_tmp = ft_strcopy(cub->map->map, cub);
	if (!map_tmp)
		return (1);
	if (verif_character_map(map_tmp, cub) == 1)
	{
		ft_free(map_tmp);
		return (1);
	}
	if (flood_fill(map_tmp, cub->player->pos_x, cub->player->pos_y, 0) == 1)
	{
		ft_free(map_tmp);
		write(2, "Error map not good\n", 19);
		return (1);
	}
	ft_free(map_tmp);
	return (0);
}
