/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:31:44 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/20 15:43:58 by tcybak           ###   ########.fr       */
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
	if (x < 0 || y < 0 || (int)strlen_line(cub) <= y
		|| (int)ft_strlen(cub[y]) <= x || cub[y][x] == ' ')
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

int	ft_transfer_map(t_cub *cub, char *tab)
{
	int	i;
	int	j;
	int	z;
	int	line_size;

	i = 0;
	j = 0;
	while (tab && tab[i])
	{
		z = 0;
		line_size = 0;
		while (tab[i + line_size] && tab[i + line_size] != '\n')
			line_size++;
		cub->map->map[j] = ft_calloc(line_size + 1, sizeof(char));
		if (!cub->map->map[j])
			return (1);
		while (tab[i] && tab[i] != '\n')
			cub->map->map[j][z++] = tab[i++];
		if (tab[i] == '\n')
			i++;
		j++;
	}
	free(tab);
	return (0);
}
