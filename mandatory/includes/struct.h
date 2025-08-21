/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/21 10:43:03 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_win
{
	int			x;
	int			y;
	float		win_x;
	float		win_y;
	mlx_window	window;
}	t_win;

typedef struct s_ray
{
	int			side;
	int			ray_x;
	int			ray_y;
	int			height;
	float		cosx;
	float		siny;
	float		delx;
	float		dely;
	float		dx;
	float		dy;
	float		dist;
	float		dist_wall;
	float		ray_angle;
	float		start_y;
	float		save_start_y;
	float		end_y;
	float		wall_x;
	float		wall_y;
	float		tex_x;
	float		tex_y;
	float		text_step;
	float		text_start;
	float		text_pos;
	mlx_color	pixel_color;
}	t_ray;

typedef struct s_player
{
	int		stepx;
	int		stepy;
	int		angle;
	int		arrow_left;
	int		arrow_right;
	char	chara;
	float	pos_x;
	float	pos_y;
	float	player_angle;
}	t_player;

typedef struct s_map
{
	char		**map;
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;

	int			w_n;
	int			h_n;
	int			w_s;
	int			h_s;
	int			w_e;
	int			h_e;
	int			w_o;
	int			h_o;
	int			size_ver;
	int			nb_player;
}	t_map;

typedef struct s_parsing
{
	char		*f_path_tmp;
	char		*c_path_tmp;
	int			count_ver;
	int			y;
	int			count;
}	t_parsing;

typedef enum s_image
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SIZE,
}	t_image;

typedef struct s_cub
{
	mlx_image	img[SIZE];
	int			key[250];
	t_parsing	*pars;
	t_map		*map;
	t_player	*player;
	t_win		*win;
	t_ray		*ray;
	mlx_context	mlx;
	mlx_color	ground;
	mlx_color	sky;
}	t_cub;

#endif