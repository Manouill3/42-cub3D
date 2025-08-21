/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:13:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/21 09:43:07 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	check_y(float y, float x, char c, t_map *map)
{
	return (map->map[(int)(y + 0.9) - 1][(int)x] != c
		&& map->map[(int)(y + 0.1)][(int)x] != c);
}

int	check_x(float y, float x, char c, t_map *map)
{
	return (map->map[(int)y][(int)(x + 0.9) - 1] != c
		&& map->map[(int)y][(int)(x + 0.1)] != c);
}

void	apply_position(t_player *player, t_map *map, float x, float y)
{
	if (check_y(y, x, '1', map) && check_x(y, x, '1', map))
	{
		player->pos_y = y;
		player->pos_x = x;
	}
}
