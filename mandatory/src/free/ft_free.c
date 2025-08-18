/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsug <tsug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/18 02:41:18 by tsug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_destroy(t_cub *cub)
{
	if (cub->img[NORTH])
		mlx_destroy_image(cub->mlx, cub->img[NORTH]);
	if (cub->img[SOUTH])
		mlx_destroy_image(cub->mlx, cub->img[SOUTH]);
	if (cub->img[EAST])
		mlx_destroy_image(cub->mlx, cub->img[EAST]);
	if (cub->img[WEST])
		mlx_destroy_image(cub->mlx, cub->img[WEST]);
	mlx_destroy_window(cub->mlx, cub->win->window);
	mlx_destroy_context(cub->mlx);
}

void	ft_free_path(t_cub *cub)
{
    t_map *map = cub->map;
    
    if (map->n_path)
    {
        free(map->n_path);
        map->n_path = NULL;
    }
    if (map->s_path)
    {
        free(map->s_path);
        map->s_path = NULL;
    }
    if (map->e_path)
    {
        free(map->e_path);
        map->e_path = NULL;
    }
    if (map->w_path)
    {
        free(map->w_path);
        map->w_path = NULL;
    }
}

void	free_all(t_cub *cub)
{
	if (cub->map && cub->map->map)
		ft_free(cub->map->map);
	if (cub->map)
	{
		ft_free_path(cub);
		free(cub->map);
	}
	if (cub->player)
		free(cub->player);
	if (cub->win)
		free(cub->win);
	if (cub->ray)
		free(cub->ray);
	if (cub)
		free(cub);
}
