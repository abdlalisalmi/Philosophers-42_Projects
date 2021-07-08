/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/08 13:51:50 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	max_number_of_eat_check(t_philo *philo)
{
	int	i;
	int	done;

	if (philo[0].n_t_eat != -1)
	{
		done = 1;
		i = -1;
		while (++i < philo[0].n_philo)
			if (philo[i].total_eat < philo[i].n_t_eat)
				done = 0;
		if (done)
		{
			printf ("%sAll philosophers have eaten at least", RED);
			printf (" %d times each\n", philo[0].n_t_eat);
			i = -1;
			while (++i < philo[0].n_philo)
			{
				printf ("philosopher %d", philo[i].id + 1);
				printf (" total eat = %d\n", philo[i].total_eat);
			}
			exit(EXIT_SUCCESS);
			free_leaks(philo);
		}
	}
}

void	*supervisor(void *parm)
{
	t_philo			*philo;
	int				time;
	int				i;

	philo = (t_philo *)parm;
	while (1)
	{
		i = -1;
		while (++i < philo[0].n_philo)
		{
			time = get_timestamp() - philo[i].time;
			if ((time - philo[i].last_eat) >= (int)philo[i].t_die
				&& philo[i].status != EATING)
			{
				philo[i].status = DEAD;
				output(get_timestamp(), &philo[i], "died", RED);
				return (NULL);
				//exit(EXIT_FAILURE);
			}
		}
		max_number_of_eat_check(philo);
	}
	return (NULL);
}
