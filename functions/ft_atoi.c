/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:58:21 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/29 17:12:46 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_number(const char *str, int i)
{
	long	result;

	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || i > 10)
			exit_program("Some Arguments Are Not Integers\n", 1);
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
		exit_program("Incorrectly Formatted\n", 1);
	result = get_number(str, i);
	if (result > 2147483647)
		exit_program("Some Arguments Are Bigger Than An Integer\n", 1);
	return (result);
}
