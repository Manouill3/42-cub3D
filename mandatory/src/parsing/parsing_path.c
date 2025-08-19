/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:13:18 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/19 13:43:52 by tcybak           ###   ########.fr       */
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
	int		count_ver;
	char	*line;
	char	**map_tmp;
	char	*f_path_tmp = NULL;
	char	*c_path_tmp = NULL;

	y = 0;
	count = 0;
	count_ver = 0;
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
			count_ver++;
			continue;
		}
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			cub->map->s_path = ft_path_picture(line + 2);
			y++;
			count++;
			count_ver++;
			continue;
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			cub->map->w_path = ft_path_picture(line + 2);
			y++;
			count++;
			count_ver++;
			continue;
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			cub->map->e_path = ft_path_picture(line + 2);
			y++;
			count++;
			count_ver++;
			continue;
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			f_path_tmp = ft_path_picture(line + 2);
			y++;
			count++;
			count_ver++;
			continue;
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			c_path_tmp = ft_path_picture(line + 2);
			y++;
			count++;
			count_ver++;
			continue;
		}
		break;
	}
	char	**RGB = NULL;

	if (f_path_tmp)
	{
		RGB = ft_split(f_path_tmp, ',');
		free(f_path_tmp);
		f_path_tmp = NULL;
		if (!RGB || !RGB[0] || !RGB[1] || !RGB[2])
			return ;
		cub->ground.r = ft_atoi(RGB[0]);
		cub->ground.g = ft_atoi(RGB[1]);
		cub->ground.b = ft_atoi(RGB[2]);
		ft_free(RGB);
		free(f_path_tmp);
	}
	if (c_path_tmp)
	{
		RGB = ft_split(c_path_tmp, ',');
		free(c_path_tmp);
		c_path_tmp = NULL;
		if (!RGB || !RGB[0] || !RGB[1] || !RGB[2])
			return ;
		cub->sky.r = ft_atoi(RGB[0]);
		cub->sky.g = ft_atoi(RGB[1]);
		cub->sky.b = ft_atoi(RGB[2]);
		ft_free(RGB);
		free(c_path_tmp);
	}
	free(map_tmp);
	if (count_ver != 6)
	{
		write(2, "Error\nMissing element or too many elements\n", 43);
		free_all(cub);
		exit (1);
	}
	ft_new_map(cub, map_tmp, count);
}
