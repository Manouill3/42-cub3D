/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:38:56 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/21 09:39:19 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	ft_number_separator(char *str, char s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == s)
			count++;
		i++;
	}
	return (count);
}

int	ft_count_separator(char *path)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(path && path[i])
	{
		if (path[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		return (-1);
	else
		return (0);
}
