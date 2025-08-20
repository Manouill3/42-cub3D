/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:01:47 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/20 15:58:23 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	ft_verif_rgb(char **rgb, char **map_tmp, t_cub *cub)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (i > 2)
			ft_error_path(map_tmp, cub,
				"Error\nMissing element or too many elements\n", rgb);
		if (char_in_color(rgb[i]))
			ft_error_path(map_tmp, cub,
				"Error\nMissing element or too many elements\n", rgb);
		i++;
	}
}

void	ft_give_path_row(t_cub *cub, char **map_tmp)
{
	int	y;

	y = cub->pars->y;
	if (ft_strncmp(map_tmp[y], "EA", 2) == 0)
	{
		if (cub->map->e_path != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->map->e_path = ft_path_picture(map_tmp[y] + 2);
	}
	else if (ft_strncmp(map_tmp[y], "F ", 2) == 0)
	{
		if (cub->pars->f_path_tmp != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->pars->f_path_tmp = ft_path_picture(map_tmp[y] + 2);
	}
	else if (ft_strncmp(map_tmp[y], "C ", 2) == 0)
	{
		if (cub->pars->c_path_tmp != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->pars->c_path_tmp = ft_path_picture(map_tmp[y] + 2);
	}
}

void	ft_give_path(t_cub *cub, char **map_tmp)
{
	int	y;

	y = cub->pars->y;
	if (ft_strncmp(map_tmp[y], "NO", 2) == 0)
	{
		if (cub->map->n_path != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->map->n_path = ft_path_picture(map_tmp[y] + 2);
	}
	else if (ft_strncmp(map_tmp[y], "SO", 2) == 0)
	{
		if (cub->map->s_path != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->map->s_path = ft_path_picture(map_tmp[y] + 2);
	}
	else if (ft_strncmp(map_tmp[y], "WE", 2) == 0)
	{
		if (cub->map->w_path != NULL)
			ft_error_path(map_tmp, cub,
				"Error\nSame Element\n", NULL);
		cub->map->w_path = ft_path_picture(map_tmp[y] + 2);
	}
	ft_give_path_row(cub, map_tmp);
}

int	parse_line(t_cub *cub, char **map_tmp)
{
	int	y;

	y = cub->pars->y;
	if (ft_empty_line(map_tmp[y]))
	{
		cub->pars->y++;
		cub->pars->count++;
		return (1);
	}
	if (ft_strncmp(map_tmp[y], "NO", 2) == 0
		|| ft_strncmp(map_tmp[y], "SO", 2) == 0
		|| ft_strncmp(map_tmp[y], "WE", 2) == 0
		|| ft_strncmp(map_tmp[y], "EA", 2) == 0
		|| ft_strncmp(map_tmp[y], "F ", 2) == 0
		|| ft_strncmp(map_tmp[y], "C ", 2) == 0)
	{
		ft_give_path(cub, map_tmp);
		cub->pars->y++;
		cub->pars->count++;
		cub->pars->count_ver++;
		return (1);
	}
	return (0);
}

int	char_in_color(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
