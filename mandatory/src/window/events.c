/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/14 13:20:00 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	move_right(t_cub *cub)
{
	float	cosx;
	float	siny;
	float	tmp_x;
	float	tmp_y;

	cosx = cos(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	tmp_x = cub->player->pos_x + cosx;
	tmp_y = cub->player->pos_y + siny;
	apply_position(cub->player, cub->map, tmp_x, tmp_y);
}

void	move_left(t_cub *cub)
{
	float	cosx;
	float	siny;
	float	tmp_x;
	float	tmp_y;

	cosx = cos(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	siny = sin(((cub->player->angle + 90) % 360) * (PI / 180)) * 0.1;
	tmp_x = cub->player->pos_x - cosx;
	tmp_y = cub->player->pos_y - siny;
	apply_position(cub->player, cub->map, tmp_x, tmp_y);
}

void	move_backward(t_cub *cub)
{
	float	cosx;
	float	siny;
	float	tmp_x;
	float	tmp_y;

	cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
	tmp_x = cub->player->pos_x - cosx;
	tmp_y = cub->player->pos_y - siny;
	apply_position(cub->player, cub->map, tmp_x, tmp_y);
}

void	move_forward(t_cub *cub)
{
	float	cosx;
	float	siny;
	float	tmp_x;
	float	tmp_y;

	cosx = cos((cub->player->angle % 360) * (PI / 180)) * 0.1;
	siny = sin((cub->player->angle % 360) * (PI / 180)) * 0.1;
	tmp_x = cub->player->pos_x + cosx + (0.1f * -(cub->player->angle > 180));
	tmp_y = cub->player->pos_y + siny + (0.1f * -(cub->player->angle > 180));
	apply_position(cub->player, cub->map, tmp_x, tmp_y);
}

void	move(t_cub *cub)
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
