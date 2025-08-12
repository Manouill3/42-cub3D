/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:40:43 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/12 13:47:26 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void    get_texture2(t_cub *cub, int i)
{
    cub->ray->wall_y = cub->player->pos_y + cub->ray->dist_wall * cub->ray->siny;
    cub->ray->wall_y = cub->ray->wall_y - floor(cub->ray->wall_y);
    if (cub->player->stepx == -1)
    {
        cub->ray->tex_x = (int)(cub->ray->wall_y * cub->map->w_o);
        while (cub->ray->start_y < cub->ray->end_y)
        {
            cub->ray->tex_y = (int)(((cub->ray->start_y - cub->ray->save_start_y) * cub->map->h_o) / cub->ray->height);
            cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx, cub->img[WEST], cub->ray->tex_x, cub->ray->tex_y);
            mlx_pixel_put_region(cub->mlx, cub->win->window, i, cub->ray->start_y, 16, 16 , &cub->ray->pixel_color);
            cub->ray->start_y++;
        }
    }
    else
    {
        cub->ray->tex_x = (int)(cub->ray->wall_y * cub->map->w_e);
        while (cub->ray->start_y < cub->ray->end_y)
        {
            cub->ray->tex_y = (int)(((cub->ray->start_y - cub->ray->save_start_y) * cub->map->h_e) / cub->ray->height);
            cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx, cub->img[EAST], cub->ray->tex_x, cub->ray->tex_y);
            mlx_pixel_put_region(cub->mlx, cub->win->window, i, cub->ray->start_y, 16, 16 , &cub->ray->pixel_color);
            cub->ray->start_y++;
        }
    }
}

void    get_texture1(t_cub *cub, int i)
{
    cub->ray->wall_x = cub->player->pos_x + cub->ray->dist_wall * cub->ray->cosx;
    cub->ray->wall_x = cub->ray->wall_x - floor(cub->ray->wall_x);
    if (cub->player->stepy == -1)
    {
        cub->ray->tex_x = (int)(cub->ray->wall_x * cub->map->w_s);
        while (cub->ray->start_y < cub->ray->end_y)
        {
            cub->ray->tex_y = (int)(((cub->ray->start_y - cub->ray->save_start_y) * cub->map->h_s) / cub->ray->height);
            cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx, cub->img[SOUTH], cub->ray->tex_x, cub->ray->tex_y);
            mlx_pixel_put_region(cub->mlx, cub->win->window, i, cub->ray->start_y, 16, 16 , &cub->ray->pixel_color);
            cub->ray->start_y++;
        }
    }
    else
    {
        cub->ray->tex_x = (int)(cub->ray->wall_x * cub->map->w_n);
        while (cub->ray->start_y < cub->ray->end_y)
        {
            cub->ray->tex_y = (int)(((cub->ray->start_y - cub->ray->save_start_y) * cub->map->h_n) / cub->ray->height);
            cub->ray->pixel_color = mlx_get_image_pixel(cub->mlx, cub->img[NORTH], cub->ray->tex_x, cub->ray->tex_y);
            mlx_pixel_put_region(cub->mlx, cub->win->window, i, cub->ray->start_y, 16,  16, &cub->ray->pixel_color);
            cub->ray->start_y++;
        }
    }
}

void    get_dist(t_cub *cub, int i)
{
    cub->ray->dist_wall = cub->ray->dist;
    cub->ray->ray_angle = ((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0);
    cub->player->player_angle = (cub->player->angle % 360) * (PI / 180.0);
    cub->ray->dist = cub->ray->dist * cos(cub->ray->ray_angle - cub->player->player_angle);
    cub->ray->height = HEIGHT / cub->ray->dist;
    cub->ray->start_y = (-cub->ray->height / 2) + (HEIGHT / 2);
    if (cub->ray->start_y < 0)
        cub->ray->start_y = 0;
    cub->ray->end_y = cub->ray->start_y + cub->ray->height;
    if (cub->ray->end_y > HEIGHT)
        cub->ray->end_y = HEIGHT - 1;
}

void    get_ray_sup(t_cub *cub)
{
    while (1)
    {
        if (cub->ray->ray_y < 0 || cub->ray->ray_x < 0 || cub->ray->ray_y > cub->map->size_ver - 1 || (int)ft_strlen(cub->map->map[cub->ray->ray_y]) < cub->ray->ray_x)
            break ;
        if (cub->map->map[cub->ray->ray_y][cub->ray->ray_x] && cub->map->map[cub->ray->ray_y][cub->ray->ray_x] == '1')
            break;
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
    if (cub->ray->side == 1)
        cub->ray->dist = (cub->ray->dx - cub->ray->delx);
    else
        cub->ray->dist = (cub->ray->dy - cub->ray->dely);
}

void    sky_and_ground(t_cub *cub, int i)
{
    int y;
    
    get_ray_sup(cub);
    get_dist(cub, i);
    cub->ray->save_start_y = cub->ray->start_y;
    if (cub->ray->side == 0)
        get_texture1(cub, i);
    if (cub->ray->side == 1)
        get_texture2(cub, i);
    y = 0;
    while (y < cub->ray->save_start_y)
    {
        mlx_pixel_put(cub->mlx, cub->win->window, i, y, color(0x00FFFFFF));
        y++;
    }
    y = cub->ray->end_y;
    while (y < HEIGHT)
    {
        mlx_pixel_put(cub->mlx, cub->win->window, i, y, color(0xf1c232FF));
        y++;
    }
}

void    get_data(t_cub *cub, int i)
{
    cub->ray->ray_x = (int)cub->player->pos_x;
    cub->ray->ray_y = (int)cub->player->pos_y;
    cub->ray->cosx = cos(((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0));
    cub->ray->siny = sin(((cub->player->angle % 360 - FOV / 2) + i * FOV / (float)WIDTH) * (PI / 180.0));
    cub->ray->delx = sqrt(1 + (cub->ray->siny * cub->ray->siny) / (cub->ray->cosx * cub->ray->cosx));
    cub->ray->dely = sqrt(1 + (cub->ray->cosx * cub->ray->cosx) / (cub->ray->siny * cub->ray->siny));
}

void    get_ray(t_cub *cub, int i)
{
    get_data(cub, i);
    if (cub->ray->cosx > 0)
    {
        cub->player->stepx = 1;
        cub->ray->dx = (1 - (cub->player->pos_x - (float)cub->ray->ray_x)) * cub->ray->delx;
    }
    else
    {
        cub->player->stepx = -1;
        cub->ray->dx = (cub->player->pos_x - (float)cub->ray->ray_x) * cub->ray->delx;
    }
    if (cub->ray->siny > 0)
    {
        cub->player->stepy = 1;
        cub->ray->dy = (1 - (cub->player->pos_y - (float)cub->ray->ray_y)) * cub->ray->dely;
    }
    else
    {
        cub->player->stepy = -1;
        cub->ray->dy = (cub->player->pos_y - (float)cub->ray->ray_y) * cub->ray->dely;
    }
    sky_and_ground(cub, i);
}

void	raycast(void *param)
{
	int		i;
	t_cub	*cub;

    i = 0;
	cub = (t_cub *)param;
	mlx_clear_window(cub->mlx, cub->win->window, color(0x000000FF));
	if (cub->player->arrow_left)
		cub->player->angle -= 1;
	if (cub->player->arrow_right)
		cub->player->angle += 1;
	while (i < WIDTH)
    {
		get_ray(cub, i);
        i++;
    }
    ft_draw_map(cub);
    ft_draw_player(cub);
	move(cub);
}


