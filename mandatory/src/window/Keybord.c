/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 07:35:52 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/12 11:50:47 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void event_window(int event, void *param)
{
    t_cub *cub;
    
    cub = (t_cub *)param;
    if (event == 0)
    {
        ft_destroy(cub);
        free_all(cub);
        exit(0);
    }
}

void handle_key(int keycode, void *param)
{
    t_cub *cub;

    cub = (t_cub *)param;
    if (keycode == 41)
    {
        ft_destroy(cub);
        free_all(cub);
        exit(0);
    }
    if (keycode == 79)
        cub->player->arrow_right = 1;   
    if (keycode == 80)
        cub->player->arrow_left = 1;
    if (4 == keycode)
        cub->key[4] = 1;
    if (7 == keycode)
        cub->key[7] = 1;
    if (22 == keycode)
        cub->key[22] = 1;
    if (26 == keycode)
        cub->key[26] = 1;
    return ;
}
