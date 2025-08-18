/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:13:18 by tcybak            #+#    #+#             */
/*   Updated: 2025/08/18 15:14:30 by tcybak           ###   ########.fr       */
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
			cub->map->f_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			cub->map->c_path = ft_path_picture(line + 2);
			y++;
			count++;
			continue;
		}
		break;
	}
	char	**tmp_RGB;
	int		len_path;
	int		i = 0;
	int		size_path;
	int		tmp_int;
	if (cub->map->c_path)
	{
		len_path = ft_number_separator(cub->map->c_path, ',');
		tmp_RGB = ft_calloc(len_path + 1, sizeof(char));
		tmp_RGB = ft_split(cub->map->c_path, ',');
	}
	if (cub->map->f_path)
	{
		len_path = ft_number_separator(cub->map->f_path, ',');
		tmp_RGB = ft_calloc(len_path + 1, sizeof(char));
		tmp_RGB = ft_split(cub->map->f_path, ',');
		free(cub->map->f_path);
		cub->map->f_path = NULL;
		cub->map->f_path = ft_calloc(10 + 1 , sizeof(char));
		cub->map->f_path[0] = '0';
		cub->map->f_path[1] = 'x';
		size_path = 2;
		while (tmp_RGB[i])
		{
			tmp_int = ft_atoi(tmp_RGB[i]);
			tmp_RGB[i] = ft_convertisor(tmp_int, "123456789ABCDEF");
			printf("tmp_RGB[i] === %s\n", tmp_RGB[i]);
			int	j = 0;
			while (tmp_RGB[i][j])
			{
				cub->map->f_path[size_path] = tmp_RGB[i][j];
				j++;
				size_path++;
			}
			i++;
		}
	}
	printf("F = %s\n C = %s\n", cub->map->f_path, cub->map->c_path);
	ft_new_map(cub, map_tmp, count);
}
