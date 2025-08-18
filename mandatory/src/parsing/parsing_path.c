/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsug <tsug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:13:18 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/18 23:47:41 by tsug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_path_picture(char *line)
{
	int		i;
	int		start;
	int		end;
	char	*path;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == ':')
		i++;
	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	end = i;
	while (end > start && (line[end - 1] == ' ' || line[end - 1] == '\t'))
		end--;
	path = ft_calloc(end - start + 1, sizeof(char));
	if (!path)
		return (NULL);
	i = 0;
	while (start < end)
		path[i++] = line[start++];
	return (path);
}

void	only_map(t_cub *cub)
{
	int		y;
	int		count;
	char	*line;
	char	**map_tmp;
	char	*f_path_tmp;
	char	*c_path_tmp;

	y = 0;
	count = 0;
	map_tmp = ft_strcopy(cub->map->map, cub);
	while (map_tmp[y])
	{
		line = map_tmp[y];
		if (ft_empty_line(line))
		{
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "NO", 2) == 0)
		{
			cub->map->n_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			cub->map->s_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			cub->map->w_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			cub->map->e_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			f_path_tmp = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			c_path_tmp = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		break;
	}
	char	**RGB;
	int		r;
	int		g;
	int		b;

	if (f_path_tmp)
	{
		RGB = ft_split(f_path_tmp, ',');
	}
	if (c_path_tmp)
	{
		RGB = ft_split(c_path_tmp, ',');
		free(f_path_tmp);
		f_path_tmp = NULL;
		if (!RGB || !RGB[0] || !RGB[1] || !RGB[2])
			return ;
		r = ft_atoi(RGB[0]);
		g = ft_atoi(RGB[1]);
		b = ft_atoi(RGB[2]);
		cub->map->f_path =  r * 10000 + g * 100 + b;
		ft_free(RGB);
	}
	printf("cub->map->f_path = %d", cub->map->f_path);
	ft_new_map(cub, map_tmp, count);
}
