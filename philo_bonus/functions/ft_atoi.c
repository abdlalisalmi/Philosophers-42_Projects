/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:58:21 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/11 14:09:50 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

long	get_number(const char *str, int i)
{
	long	result;

	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || i > 10)
			return (0);
		result = result * 10;
		result += (int)str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	result = get_number(str, i);
	if (result > 2147483647 || result == -1)
		return (0);
	return (result);
}
