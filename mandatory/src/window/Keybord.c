/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:35:52 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/13 15:40:13 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	events(t_cub *cub)
{
	cub->player->arrow_left = 0;
	cub->player->arrow_right = 0;
	mlx_on_event(cub->mlx, cub->win->window,
		MLX_KEYDOWN, handle_key, (void *)cub);
	mlx_on_event(cub->mlx, cub->win->window,
		MLX_KEYUP, handle_key_up, (void *)cub);
	mlx_on_event(cub->mlx, cub->win->window,
		MLX_WINDOW_EVENT, event_window, (void *)cub);
	mlx_add_loop_hook(cub->mlx, raycast, cub);
	mlx_set_fps_goal(cub->mlx, 70);
	mlx_loop(cub->mlx);
}

void	event_window(int event, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (event == 0)
	{
		ft_destroy(cub);
		free_all(cub);
		exit(0);
	}
}

void	handle_key(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == 41)
	{
		ft_destroy(cub);
		free_all(cub);
		exit(0);
	}
	if (keycode == 79)
		cub->player->arrow_right = 1;
	if (keycode == 80)
		cub->player->arrow_left = 1;
	if (4 == keycode)
		cub->key[4] = 1;
	if (7 == keycode)
		cub->key[7] = 1;
	if (22 == keycode)
		cub->key[22] = 1;
	if (26 == keycode)
		cub->key[26] = 1;
	return ;
}

void	handle_key_up(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == 79)
		cub->player->arrow_right = 0;
	if (keycode == 80)
		cub->player->arrow_left = 0;
	if (4 == keycode)
		cub->key[4] = 0;
	if (7 == keycode)
		cub->key[7] = 0;
	if (22 == keycode)
		cub->key[22] = 0;
	if (26 == keycode)
		cub->key[26] = 0;
	return ;
}
