/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/12 11:48:33 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    move_right(t_cub *cub)
{
    float   cosx;
    float   siny;
    float   tmp_x;
    float   tmp_y;

    cosx = cos(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
    tmp_x = cub->player->pos_x + cosx;
    tmp_y = cub->player->pos_y + siny;
    if (cub->map->map[(int)tmp_y][(int)tmp_x] != '1')
    {
        cub->player->pos_y += siny;
        cub->player->pos_x += cosx;    
    }
}

void    move_left(t_cub *cub)
{
    float   cosx;
    float   siny;
    float   tmp_x;
    float   tmp_y;

    cosx = cos(((cub->player->angle - 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle - 90) % 360) * (PI / 180)) * 0.1;
    tmp_x = cub->player->pos_x + cosx;
    tmp_y = cub->player->pos_y + siny;
    if (cub->map->map[(int)tmp_y][(int)tmp_x] != '1')
    {
        cub->player->pos_y += siny;
        cub->player->pos_x += cosx;    
    }
}

void    move_backward(t_cub *cub)
{
    float   cosx;
    float   siny;
    float   tmp_x;
    float   tmp_y;

    cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
    tmp_x = cub->player->pos_x - cosx;
    tmp_y = cub->player->pos_y - siny;
    if (cub->map->map[(int)tmp_y][(int)tmp_x] != '1')
    {
        cub->player->pos_y -= siny;
        cub->player->pos_x -= cosx;    
    }
}

void    move_forward(t_cub *cub)
{
    float   cosx;
    float   siny;
    float   tmp_x;
    float   tmp_y;

    cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
    tmp_x = cub->player->pos_x + cosx;
    tmp_y = cub->player->pos_y + siny;
    if (cub->map->map[(int)tmp_y][(int)tmp_x] != '1')
    {
        cub->player->pos_y += siny;
        cub->player->pos_x += cosx;    
    }
}

void    move(t_cub *cub)
{
    if (cub->key[4] == 1)
        move_left(cub);
    if (cub->key[7] == 1)
        move_right(cub);
    if (cub->key[26] == 1)
        move_forward(cub);
    if (cub->key[22] == 1)
        move_backward(cub);
}

void handle_key_up(int keycode, void *param)
{
    t_cub *cub;

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

void    events(t_cub *cub)
{
    cub->player->arrow_left = 0;
    cub->player->arrow_right = 0;
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYDOWN, handle_key, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_KEYUP, handle_key_up, (void *)cub);
    mlx_on_event(cub->mlx, cub->win->window, MLX_WINDOW_EVENT, event_window, (void *)cub);
    mlx_add_loop_hook(cub->mlx, raycast, cub);
    mlx_set_fps_goal(cub->mlx, 70);
    mlx_loop(cub->mlx);
}
