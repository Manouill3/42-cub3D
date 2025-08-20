/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:13:18 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/20 23:34:37 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

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
	while (line[i] == ' ' || line[i] == '\t')
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

void	ft_path_color_ground(t_cub *cub, char **map_tmp)
{
	int		i;
	char	**rgb;

	i = 0;
	rgb = NULL;
	if (cub->pars->f_path_tmp)
	{
		i = ft_count_separator(cub->pars->f_path_tmp);
		rgb = ft_split(cub->pars->f_path_tmp, ',');
		free(cub->pars->f_path_tmp);
		cub->pars->f_path_tmp = NULL;
		if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || i == -1)
			ft_error_path(map_tmp, cub,
				"Error\nMissing element or too many elements\n", rgb);
		cub->ground.r = ft_atoi(rgb[0]);
		cub->ground.g = ft_atoi(rgb[1]);
		cub->ground.b = ft_atoi(rgb[2]);
		// printf("RGB 0 = %s\n RGB 1 = %s\n RGB 2 = %s\n", rgb[0], rgb[1], rgb[2]);
		ft_verif_rgb(rgb, map_tmp, cub);
		if ((ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
			|| (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
			|| (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0))
			ft_error_path(map_tmp, cub, "Error\nColor rgb too high\n", rgb);
		ft_free(rgb);
		free(cub->pars->f_path_tmp);
	}
}

void	ft_path_color_sky(t_cub *cub, char **map_tmp)
{
	int		i;
	char	**rgb;

	i = 0;
	rgb = NULL;
	if (cub->pars->c_path_tmp)
	{
		i = ft_count_separator(cub->pars->f_path_tmp);
		rgb = ft_split(cub->pars->c_path_tmp, ',');
		free(cub->pars->c_path_tmp);
		cub->pars->c_path_tmp = NULL;
		if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || i == -1)
			ft_error_path(map_tmp, cub,
				"Error\nMissing element or too many elements\n", rgb);
		cub->sky.r = ft_atoi(rgb[0]);
		cub->sky.g = ft_atoi(rgb[1]);
		cub->sky.b = ft_atoi(rgb[2]);
		ft_verif_rgb(rgb, map_tmp, cub);
		// printf("RGB 0 = %s\n RGB 1 = %s\n RGB 2 = %s\n", rgb[0], rgb[1], rgb[2]);
		if ((ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
			|| (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
			|| (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0))
			ft_error_path(map_tmp, cub, "Error\nColor rgb too high\n", rgb);
		ft_free(rgb);
		free(cub->pars->c_path_tmp);
	}
}

void	only_map(t_cub *cub)
{
	char	**map_tmp;

	cub->pars->f_path_tmp = NULL;
	cub->pars->c_path_tmp = NULL;
	cub->pars->y = 0;
	cub->pars->count = 0;
	cub->pars->count_ver = 0;
	cub->map->e_path = NULL;
	cub->map->n_path = NULL;
	cub->map->s_path = NULL;
	cub->map->w_path = NULL;
	map_tmp = ft_strcopy(cub->map->map, cub);
	while (map_tmp[cub->pars->y])
	{
		if (!parse_line(cub, map_tmp))
			break ;
	}
	ft_path_color_ground(cub, map_tmp);
	ft_path_color_sky(cub, map_tmp);
	if (cub->pars->count_ver != 6)
		ft_error_path(map_tmp, cub,
			"Error\nMissing element or too many elements\n", NULL);
	ft_new_map(cub, map_tmp, cub->pars->count);
}
