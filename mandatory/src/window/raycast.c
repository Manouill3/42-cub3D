/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsug <tsug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:40:43 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/18 01:01:25 by tsug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	get_ray_sup(t_cub *cub)
{
	cub->ray->side = 0;
	while (1)
	{
		if (cub->ray->ray_y < 0 || cub->ray->ray_x < 0
			|| cub->ray->ray_y > cub->map->size_ver - 1
			|| (int)ft_strlen(cub->map->map[cub->ray->ray_y]) < cub->ray->ray_x)
			break ;
		if (cub->map->map[cub->ray->ray_y][cub->ray->ray_x]
				&& cub->map->map[cub->ray->ray_y][cub->ray->ray_x] == '1')
			break ;
		get_ray_side(cub);
	}
	if (cub->ray->side == 1)
		cub->ray->dist = (cub->ray->dx - cub->ray->delx);
	else
		cub->ray->dist = (cub->ray->dy - cub->ray->dely);
}

void	call_text(t_cub *cub, int i)
{
	get_ray_sup(cub);
	get_dist(cub, i);
	cub->ray->save_start_y = cub->ray->start_y;
	if (cub->ray->side == 0)
		get_texture1(cub, i);
	if (cub->ray->side == 1)
		get_texture2(cub, i);
}

void	get_data(t_cub *cub, int i)
{
	cub->ray->ray_x = (int)cub->player->pos_x;
	cub->ray->ray_y = (int)cub->player->pos_y;
	cub->ray->cosx = cos(((cub->player->angle % 360 - FOV / 2)
				+ i * FOV / (float)WIDTH) * (PI / 180.0));
	cub->ray->siny = sin(((cub->player->angle % 360 - FOV / 2)
				+ i * FOV / (float)WIDTH) * (PI / 180.0));
	cub->ray->delx = sqrt(1 + (cub->ray->siny * cub->ray->siny)
			/ (cub->ray->cosx * cub->ray->cosx));
	cub->ray->dely = sqrt(1 + (cub->ray->cosx * cub->ray->cosx)
			/ (cub->ray->siny * cub->ray->siny));
}

void	get_ray(t_cub *cub, int i)
{
	if (cub->ray->cosx > 0)
	{
		cub->player->stepx = 1;
		cub->ray->dx = (1 - (cub->player->pos_x
					- (float)cub->ray->ray_x)) * cub->ray->delx;
	}
	else
	{
		cub->player->stepx = -1;
		cub->ray->dx = (cub->player->pos_x
				- (float)cub->ray->ray_x) * cub->ray->delx;
	}
	if (cub->ray->siny > 0)
	{
		cub->player->stepy = 1;
		cub->ray->dy = (1 - (cub->player->pos_y
					- (float)cub->ray->ray_y)) * cub->ray->dely;
	}
	else
	{
		cub->player->stepy = -1;
		cub->ray->dy = (cub->player->pos_y
				- (float)cub->ray->ray_y) * cub->ray->dely;
	}
	call_text(cub, i);
}

void	raycast(void *param)
{
	int		i;
	t_cub	*cub;

	i = 0;
	cub = (t_cub *)param;
	mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
	if (cub->player->arrow_left)
		cub->player->angle -= 2;
	if (cub->player->arrow_right)
		cub->player->angle += 2;
	sky_ground(cub);
	while (i < WIDTH)
	{
		init_ray(cub->ray);
		get_data(cub, i);
		get_ray(cub, i);
		i++;
	}
	ft_draw_map(cub);
	ft_draw_player(cub);
	move(cub);
}
