/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:01:47 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/20 14:05:30 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	ft_give_path(t_cub *cub, char **map_tmp)
{
	int	y;

	y = cub->pars->y;
	if (ft_strncmp(map_tmp[y], "NO", 2) == 0)
		cub->map->n_path = ft_path_picture(map_tmp[y] + 2);
	else if (ft_strncmp(map_tmp[y], "SO", 2) == 0)
		cub->map->s_path = ft_path_picture(map_tmp[y] + 2);
	else if (ft_strncmp(map_tmp[y], "WE", 2) == 0)
		cub->map->w_path = ft_path_picture(map_tmp[y] + 2);
	else if (ft_strncmp(map_tmp[y], "EA", 2) == 0)
		cub->map->e_path = ft_path_picture(map_tmp[y] + 2);
	else if (ft_strncmp(map_tmp[y], "F ", 2) == 0)
		cub->pars->f_path_tmp = ft_path_picture(map_tmp[y] + 2);
	else if (ft_strncmp(map_tmp[y], "C ", 2) == 0)
		cub->pars->c_path_tmp = ft_path_picture(map_tmp[y] + 2);
	cub->pars->y++;
	cub->pars->count++;
	cub->pars->count_ver++;
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
		return (1);
	}
	return (0);
}
