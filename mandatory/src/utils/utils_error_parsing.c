/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:29:43 by tcybak            #+#    #+#             */
/*   Updated: 2025/09/02 11:02:52 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	error_parsing(int x, int y, char **map_tmp, t_cub *cub)
{
	char	*txt;
	char	*txt2;

	txt = "Error\nThe characters to create the map are not compliant\n";
	txt2 = "Error\nMap too big\n";
	if (x > 150 || y > 150)
	{
		write (2, txt2, 17);
		return (1);
	}
	if (ft_charac_accetable(map_tmp[y][x], cub, x, y) == 1)
	{
		write (2, txt, 58);
		return (1);
	}
	return (0);
}

int	check_error(t_cub *cub, char *tab)
{
	if (ft_map_tab(cub, tab))
	{
		write(2, "Error\nMap not good\n", 19);
		return (1);
	}
	return (0);
}
