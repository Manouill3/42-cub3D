/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsug <tsug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:15:27 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/18 02:01:05 by tsug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	ft_draw_player(t_cub *cub)
{
	int	win_x;
	int	win_y;

	win_y = 0;
	while (win_y < 2)
	{
		win_x = 0;
		while (win_x < 2)
		{
			mlx_pixel_put(cub->mlx, cub->win->window,
				win_x + cub->player->pos_x * 8,
				win_y + cub->player->pos_y * 8, color(0x0000FFFF));
			win_x++;
		}
		win_y++;
	}
}

void	get_player_angle(t_cub *cub)
{
	if (cub->player->chara == 'N')
		cub->player->angle = 270;
	if (cub->player->chara == 'S')
		cub->player->angle = 90;
	if (cub->player->chara == 'E')
		cub->player->angle = 0;
	if (cub->player->chara == 'W')
		cub->player->angle = 180;
}

void	init_text(t_cub *cub)
{
	if (!cub->map->n_path)
		cub->img[NORTH] = mlx_new_image_from_file(cub->mlx,
				"./includes/pictures/me.png", &cub->map->w_n, &cub->map->h_n);
	else
		cub->img[NORTH] = mlx_new_image_from_file(cub->mlx,
				cub->map->n_path, &cub->map->w_n, &cub->map->h_n);
	if (!cub->map->s_path)
		cub->img[SOUTH] = mlx_new_image_from_file(cub->mlx,
			"./includes/pictures/chat_sud.png", &cub->map->w_s, &cub->map->h_s);
	else
		cub->img[SOUTH] = mlx_new_image_from_file(cub->mlx,
			cub->map->s_path, &cub->map->w_s, &cub->map->h_s);
	if (!cub->map->e_path)
		cub->img[EAST] = mlx_new_image_from_file(cub->mlx,
			"./includes/pictures/chat_est.png", &cub->map->w_e, &cub->map->h_e);
	else
		cub->img[EAST] = mlx_new_image_from_file(cub->mlx,
			cub->map->e_path, &cub->map->w_e, &cub->map->h_e);
	if (!cub->map->w_path)
		cub->img[WEST] = mlx_new_image_from_file(cub->mlx,
			"./includes/pictures/chat_ouest.png",
			&cub->map->w_o, &cub->map->h_o);
	else
		cub->img[WEST] = mlx_new_image_from_file(cub->mlx,
			cub->map->w_path, &cub->map->w_o, &cub->map->h_o);
	if (!cub->img[WEST] || !cub->img[EAST]
		|| !cub->img[NORTH] || !cub->img[SOUTH])
	{
		ft_destroy(cub);
		exit(1);
	}
}

void	init_win(t_cub *cub)
{
	mlx_window_create_info	info;

	ft_memset(&info, 0, sizeof(info));
	ft_memset(cub->key, 0, 250);
	info.title = "Cub3D";
	info.width = WIDTH;
	info.height = HEIGHT;
	cub->win->window = mlx_new_window(cub->mlx, &info);
	get_player_angle(cub);
	init_text(cub);
	cub->player->arrow_left = 0;
	cub->player->arrow_right = 0;
	events(cub);
}

void	cub3d(t_cub *cub)
{
	cub->mlx = mlx_init();
	init_win(cub);
}
