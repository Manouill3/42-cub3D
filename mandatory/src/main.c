/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:30:22 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/12 14:22:22 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	check_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - 1;
	j = ft_strlen(ext) - 1;
	if (ft_strlen(file) < 4)
		return (1);
	while (j > 0)
	{
		if (ext[j] != file[i])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	init_more(t_cub *cub)
{
	cub->win = malloc(sizeof(t_win));
	if (!cub->win)
	{
		free(cub->map);
		free(cub->player);
		free(cub);
		return (1);
	}
	cub->ray = malloc(sizeof(t_ray));
	if (!cub->ray)
	{
		free(cub->win);
		free(cub->map);
		free(cub->player);
		free(cub);
		return (1);
	}
	return (0);
}

int	ft_init(t_cub **cub)
{
	*cub = malloc(sizeof(t_cub));
	if (!*cub)
		return (1);
	(*cub)->map = malloc(sizeof(t_map));
	if (!(*cub)->map)
	{
		free(*cub);
		return (1);
	}
	(*cub)->map->map = NULL;
	(*cub)->player = malloc(sizeof(t_player));
	if (!(*cub)->player)
	{
		free((*cub)->map);
		free(*cub);
		return (1);
	}
	if (init_more(*cub))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = NULL;
	if (ac == 2)
	{
		if (check_ext(av[1], ".cub"))
		{
			write(2, "bad extension\n", 14);
			return (1);
		}
		if (ft_init(&cub))
			return (0);
		if (ft_parsing(av, cub))
		{
			free_all(cub);
			return (1);
		}
		cub3d(cub);
	}
	else
		write(2, "too many or too few arguments\n", 30);
	return (0);
}
