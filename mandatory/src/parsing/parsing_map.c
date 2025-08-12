/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:31:44 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/12 14:23:45 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	strlen_line(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	flood_fill(char **cub, int x, int y, int status)
{
	if (status == 1)
		return (1);
	if (x < 0 || y < 0 || (int)ft_strlen(cub[y]) <= x
		|| (int)strlen_line(cub) <= y)
		return (1);
	if (cub[y][x] != '0' && cub[y][x] != 'N' && cub[y][x] != 'S' &&
		cub[y][x] != 'E' && cub[y][x] != 'W')
		return (status);
	cub[y][x] = 'x';
	status = flood_fill(cub, x + 1, y, status);
	status = flood_fill(cub, x - 1, y, status);
	status = flood_fill(cub, x, y + 1, status);
	status = flood_fill(cub, x, y - 1, status);
	return (status);
}
