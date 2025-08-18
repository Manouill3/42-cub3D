/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:36:25 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/18 15:09:19 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

mlx_color	color(uint32_t color)
{
	mlx_color	c;

	c.rgba = color;
	return (c);
}

void	init_ray(t_ray *ray)
{
	ray->side = 0;
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->height = 0;
	ray->cosx = 0;
	ray->siny = 0;
	ray->delx = 0;
	ray->dely = 0;
	ray->dx = 0;
	ray->dy = 0;
	ray->dist = 0;
	ray->dist_wall = 0;
	ray->ray_angle = 0;
	ray->start_y = 0;
	ray->save_start_y = 0;
	ray->end_y = 0;
	ray->wall_x = 0;
	ray->wall_y = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
}

void	get_ray_side(t_cub *cub)
{
	if (cub->ray->dx > cub->ray->dy)
	{
		cub->ray->ray_y += cub->player->stepy;
		cub->ray->dy += cub->ray->dely;
		cub->ray->side = 0;
	}
	else
	{
		cub->ray->ray_x += cub->player->stepx;
		cub->ray->dx += cub->ray->delx;
		cub->ray->side = 1;
	}
}

int	ft_number_separator(char *str, char s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == s)
			count++;
		i++;
	}
	return (count);
}
