/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:51:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/07 12:52:04 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_args(int len, char **argv, t_philo *philo)
{
	int	i;
	int	n_philo;

	if (len != 5 && len != 6)
		return (1);
	n_philo = ft_atoi(argv[1]);
	i = -1;
	while (++i < n_philo)
	{
		philo[i].n_philo = ft_atoi(argv[1]);
		philo[i].t_die = ft_atoi(argv[2]);
		philo[i].t_eat = ft_atoi(argv[3]);
		philo[i].t_sleep = ft_atoi(argv[4]);
		if (len == 6)
			philo[i].n_t_eat = ft_atoi(argv[5]);
		else
			philo[i].n_t_eat = -1;
	}
	return (0);
}
