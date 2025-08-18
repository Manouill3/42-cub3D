/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsug <tsug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:34:08 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/18 02:25:57 by tsug             ###   ########.fr       */
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

int	ft_transfer_map(t_cub *cub, char *tab)
{
	int	i;
	int	j;
	int	z;
	int	line_size;

	i = 0;
	j = 0;
	while (tab && tab[i])
	{
		z = 0;
		line_size = 0;
		while (tab[i + line_size] && tab[i + line_size] != '\n')
			line_size++;
		cub->map->map[j] = ft_calloc(line_size + 1, sizeof(char));
		if (!cub->map->map[j])
			return (1);
		while (tab[i] && tab[i] != '\n')
			cub->map->map[j][z++] = tab[i++];
		if (tab[i] == '\n')
			i++;
		j++;
	}
	free(tab);
	return (0);
}

int	verif_character_map(char **map_tmp, t_cub *cub)
{
	int		x;
	int		y;
	char	*txt;

	y = 0;
	cub->map->nb_player = 0;
	txt = "Error the characters to create the map are not compliant\n";
	while (map_tmp[y])
	{
		x = 0;
		while (map_tmp[y][x])
		{
			if (ft_charac_accetable(map_tmp[y][x], cub, x, y) == 1)
			{
				write (2, txt, 57);
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

int	ft_empty_line(char *line)
{
    int	i;

    i = 0;
    if (!line)
        return (1);
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

char	*ft_path_picture(char *line)
{
    int		i;
    int		start;
    int		end;
    char	*path;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t' || line[i] == ':')
        i++;
    start = i;
    while (line[i] && line[i] != '\n')
        i++;
    end = i;
    while (end > start && (line[end - 1] == ' ' || line[end - 1] == '\t'))
        end--;
    path = ft_calloc(end - start + 1, sizeof(char));
    if (!path)
        return (NULL);
    i = 0;
    while (start < end)
        path[i++] = line[start++];
    return (path);
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
	while (map_tmp[count])
	{
		cub->map->map[j] = ft_strdup(map_tmp[count]);
		j++;
		count++;
	}
}

void	only_map(t_cub *cub)
{
    int	y;
    int	count;
    char	*line;
	char	**map_tmp;

    y = 0;
    count = 0;
	map_tmp = ft_strcopy(cub->map->map, cub);
    while (map_tmp[y])
    {
        line = map_tmp[y];
        if (ft_empty_line(line))
        {
            y++;
            count++;
            continue;
        }
        else if (ft_strncmp(line, "NO", 2) == 0)
        {
            cub->map->n_path = ft_path_picture(line + 2);
            y++;
            count++;
            continue;
        }
        else if (ft_strncmp(line, "SO", 2) == 0)
        {
            cub->map->s_path = ft_path_picture(line + 2);
            y++;
            count++;
            continue;
        }
        else if (ft_strncmp(line, "WE", 2) == 0)
        {
            cub->map->w_path = ft_path_picture(line + 2);
            y++;
            count++;
            continue;
        }
        else if (ft_strncmp(line, "EA", 2) == 0)
        {
            cub->map->e_path = ft_path_picture(line + 2);
            y++;
            count++;
            continue;
        }
        break;
    }
	ft_new_map(cub, map_tmp, count);
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
	int	i = 0;
	while (map_tmp[i])
	{
		printf("map = %s\n", map_tmp[i]);
		i++;
	}
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
