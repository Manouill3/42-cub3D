/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:25:29 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/21 14:06:45 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"


void	get_texture2(t_cub *cub, int i)
{
	cub->ray->wall_y = cub->player->pos_y
		+ cub->ray->dist_wall * cub->ray->siny;
	cub->ray->wall_y = cub->ray->wall_y - floor(cub->ray->wall_y);
	cub->ray->text_step = 1.0 / cub->ray->height;
	cub->ray->text_start = 0.0;
	if (cub->ray->height > HEIGHT)
		cub->ray->text_start = (cub->ray->height - HEIGHT)
			/ 2.0 * cub->ray->text_step;
	if (cub->player->stepx == -1)
	{
		cub->ray->tex_x = (int)(cub->ray->wall_y * cub->map->w_e);
		while (cub->ray->start_y < cub->ray->end_y)
		{
			cub->ray->text_pos = cub->ray->text_start + (cub->ray->start_y
					- cub->ray->save_start_y) * cub->ray->text_step;
			cub->ray->tex_y = (int)(cub->ray->text_pos * cub->map->h_e);
			cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx,
					cub->img[EAST], cub->ray->tex_x, cub->ray->tex_y);
			mlx_pixel_put(cub->mlx, cub->win->window, i,
				cub->ray->start_y, cub->ray->pixel_color);
			cub->ray->start_y++;
		}
	}
	else
		get_texture_west(cub, i);
}

void	get_texture_west(t_cub *cub, int i)
{
	cub->ray->tex_x = (int)(cub->ray->wall_y * cub->map->w_w);
	while (cub->ray->start_y < cub->ray->end_y)
	{
		cub->ray->text_pos = cub->ray->text_start + (cub->ray->start_y
				- cub->ray->save_start_y) * cub->ray->text_step;
		cub->ray->tex_y = (int)(cub->ray->text_pos * cub->map->h_w);
		cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx, cub->img[WEST],
				cub->ray->tex_x, cub->ray->tex_y);
		mlx_pixel_put(cub->mlx, cub->win->window, i,
			cub->ray->start_y, cub->ray->pixel_color);
		cub->ray->start_y++;
	}
}

void	get_texture_north(t_cub *cub, int i)
{
	cub->ray->tex_x = (int)(cub->ray->wall_x * cub->map->w_n);
	while (cub->ray->start_y < cub->ray->end_y)
	{
		cub->ray->text_pos = cub->ray->text_start + (cub->ray->start_y
				- cub->ray->save_start_y) * cub->ray->text_step;
		cub->ray->tex_y = (int)(cub->ray->text_pos * cub->map->h_n);
		cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx,
				cub->img[NORTH], cub->ray->tex_x, cub->ray->tex_y);
		mlx_pixel_put(cub->mlx, cub->win->window, i,
			cub->ray->start_y, cub->ray->pixel_color);
		cub->ray->start_y++;
	}
}

void	get_texture1(t_cub *cub, int i)
{
	cub->ray->wall_x = cub->player->pos_x
		+ cub->ray->dist_wall * cub->ray->cosx;
	cub->ray->wall_x = cub->ray->wall_x - floor(cub->ray->wall_x);
	cub->ray->text_step = 1.0 / cub->ray->height;
	cub->ray->text_start = 0.0;
	if (cub->ray->height > HEIGHT)
		cub->ray->text_start = (cub->ray->height - HEIGHT)
			/ 2.0 * cub->ray->text_step;
	if (cub->player->stepy == -1)
	{
		cub->ray->tex_x = (int)(cub->ray->wall_x * cub->map->w_s);
		while (cub->ray->start_y < cub->ray->end_y)
		{
			cub->ray->text_pos = cub->ray->text_start + (cub->ray->start_y
					- cub->ray->save_start_y) * cub->ray->text_step;
			cub->ray->tex_y = (int)(cub->ray->text_pos * cub->map->h_s);
			cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx,
					cub->img[SOUTH], cub->ray->tex_x, cub->ray->tex_y);
			mlx_pixel_put(cub->mlx, cub->win->window, i,
				cub->ray->start_y, cub->ray->pixel_color);
			cub->ray->start_y++;
		}
	}
	else
		get_texture_north(cub, i);
}

void	get_dist(t_cub *cub, int i)
{
	cub->ray->dist_wall = cub->ray->dist;
	cub->ray->ray_angle = ((cub->player->angle % 360 - FOV / 2)
			+ i * FOV / (float)WIDTH) * (PI / 180.0);
	cub->player->player_angle = (cub->player->angle % 360) * (PI / 180.0);
	cub->ray->dist = cub->ray->dist * cos(cub->ray->ray_angle
			- cub->player->player_angle);
	cub->ray->height = HEIGHT / cub->ray->dist;
	cub->ray->start_y = (-cub->ray->height / 2) + (HEIGHT / 2);
	if (cub->ray->start_y < 0)
		cub->ray->start_y = 0;
	cub->ray->end_y = cub->ray->start_y + cub->ray->height;
	if (cub->ray->end_y > HEIGHT || cub->ray->end_y < 0)
		cub->ray->end_y = HEIGHT;
}
