/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:06:03 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/19 13:37:42 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	draw_free_square(t_cub *cub)
{
	cub->win->win_y = 0;
	while (cub->win->win_y < 8)
	{
		cub->win->win_x = 0;
		while (cub->win->win_x < 8)
		{
			mlx_pixel_put(cub->mlx, cub->win->window,
				cub->win->win_x + cub->win->x * 8,
				cub->win->win_y + cub->win->y * 8, color(0x00FF00FF));
			cub->win->win_x++;
		}
		cub->win->win_y++;
	}
}

void	draw_square(t_cub *cub)
{
	if (cub->map->map[cub->win->y][cub->win->x] == '1')
	{
		cub->win->win_y = 0;
		while (cub->win->win_y < 8)
		{
			cub->win->win_x = 0;
			while (cub->win->win_x < 8)
			{
				mlx_pixel_put(cub->mlx, cub->win->window,
					cub->win->win_x + cub->win->x * 8,
					cub->win->win_y + cub->win->y * 8, color(0xFFFFFFFF));
				cub->win->win_x++;
			}
			cub->win->win_y++;
		}
	}
	if (cub->map->map[cub->win->y][cub->win->x] == '0'
		|| cub->map->map[cub->win->y][cub->win->x] == 'N'
		|| cub->map->map[cub->win->y][cub->win->x] == 'S'
		|| cub->map->map[cub->win->y][cub->win->x] == 'E'
		|| cub->map->map[cub->win->y][cub->win->x] == 'W')
		draw_free_square(cub);
}

void	ft_draw_map(t_cub *cub)
{
	cub->win->x = 0;
	cub->win->y = 0;
	cub->win->win_x = 0;
	cub->win->win_y = 0;
	while (cub->map->map[cub->win->y])
	{
		cub->win->x = 0;
		while (cub->map->map[cub->win->y][cub->win->x])
		{
			draw_square(cub);
			cub->win->x++;
		}
		cub->win->y++;
	}
}

void	sky_ground(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y > HEIGHT / 2)
				mlx_pixel_put(cub->mlx, cub->win->window,
					x, y, cub->sky);
			else
				mlx_pixel_put(cub->mlx, cub->win->window,
					x, y, cub->ground);
			y++;
		}
		x++;
	}
}
