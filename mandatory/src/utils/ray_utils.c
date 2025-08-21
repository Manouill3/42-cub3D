/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:40:07 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/21 09:40:44 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

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
