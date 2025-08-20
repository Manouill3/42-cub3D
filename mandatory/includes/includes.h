/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:33 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/20 15:57:05 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# define FOV 60
# define HEIGHT 720
# define WIDTH 1280
# define PI 3.14159265
# define BUFFER_SIZE 42

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_profile.h"
# include "MacroLibX/includes/mlx_extended.h"
# include "struct.h"

// main.c //

int		    check_ext(char *file, char *ext);
int         init_more(t_cub  *cub);
int		    ft_init(t_cub **cub);

//// game ////

// cub3d.c //

void        ft_draw_player(t_cub *cub);
void	    get_player_angle(t_cub *cub);
void	    init_text(t_cub *cub);
void        init_win(t_cub *cub);
void        cub3d(t_cub *cub);

// draw_map.c //

void	    draw_free_square(t_cub *cub);
void	    draw_square(t_cub *cub);
void	    ft_draw_map(t_cub *cub);
void	    sky_ground(t_cub *cub);

//// parsing ////

// parsing_path.c //

int         ft_empty_line(char *line);
char        *ft_path_picture(char *line);
void        ft_path_color_ground(t_cub *cub, char **map_tmp);
void        ft_path_color_sky(t_cub *cub, char **map_tmp);
void	    only_map(t_cub *cub);

// parsing.c //

char	    *ft_copytab(char **map);
int	        ft_map_tab(t_cub *cub, char *tab);
int	        verif_character_map(char **map_tmp, t_cub *cub);
void	    ft_new_map(t_cub *cub, char **map_tmp, int count);
int		    ft_parsing(char **map, t_cub *cub);

// parsing map.c //

int	        strlen_line(char **map);
int	        flood_fill(char **cub, int x, int y, int status);
int	        ft_transfer_map(t_cub *cub, char *tab);

//// utils ////

// color.c //

mlx_color   color(uint32_t color);
void        init_ray(t_ray *ray);
void	    get_ray_side(t_cub *cub);
int         ft_number_separator(char *str, char s);

// get_next_line.c //

char	    *ft_select_line(char *all);
char	    *ft_select_rest(char *all);
char    	*ft_read_line(int fd, char *buf, char *stat);
char	    *get_next_line(int fd);

// utils_parsing.c //

int         ft_strlen_map(char *str);
int         ft_charac_accetable(char str, t_cub *cub, int x, int y);
int         ft_error_charac(t_cub *cub);
char        **ft_strcopy(char **str, t_cub *cub);
void	    ft_error_path(char **map_tmp, t_cub *cub, char *error, char **rgb);

// utils_parsing_path.c //

void	    ft_verif_rgb(char **rgb, char **map_tmp, t_cub *cub);
void        ft_give_path(t_cub *cub, char **map_tmp);
int         parse_line(t_cub *cub, char **map_tmp);
int         char_in_color(char *s);

//// free ////

// ft_free.c //

void        ft_free(char **str);
void	    ft_destroy(t_cub *cub);
void	    free_all(t_cub *cub);

//// window ////

// events.c //

void        move_right(t_cub *cub);
void        move_left(t_cub *cub);
void        move_backward(t_cub *cub);
void        move_forward(t_cub *cub);
void        move(t_cub *cub);

// keybord.c //

void	    events(t_cub *cub);
void        event_window(int event, void *param);
void        handle_key(int keycode, void *param);
void	    handle_key_up(int keycode, void *param);

// raycast.c //


void        get_ray_sup(t_cub *cub);
void	    call_text(t_cub *cub, int i);
void        get_data(t_cub *cub, int i);
void        get_ray(t_cub *cub, int i);
void	    raycast(void *param);


// Texture.c //

void        get_texture_east(t_cub *cub, int i);
void        get_texture2(t_cub *cub, int i);
void        get_texture_north(t_cub *cub, int i);
void        get_texture1(t_cub *cub, int i);
void        get_dist(t_cub *cub, int i);

// move.c //

int         check_y(float y, float x, char c, t_map *map);
int         check_x(float y, float x, char c, t_map *map);
void        apply_position(t_player *player, t_map *map, float x, float y);

#endif