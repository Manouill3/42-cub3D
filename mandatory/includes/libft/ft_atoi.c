/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:51:03 by mdegache          #+#    #+#             */
/*   Updated: 2025/08/19 22:36:01 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nb * sign > 255 || nb * sign < 0)
		return (-1);
	return (nb * sign);
}
