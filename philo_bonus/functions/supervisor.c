/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/12 18:51:06 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	max_number_of_eat_check(t_philo *philo)
{
	int	i;
	int	done;

	if (philo[0].state->n_t_eat != -1)
	{
		done = 1;
		i = -1;
		while (++i < philo[0].state->n_philo)
			if (philo[i].total_eat < philo[i].state->n_t_eat)
				done = 0;
		if (done)
		{
			// pthread_mutex_lock(&philo[0].state->print_lock);
			printf ("%sAll philosophers have eaten at least", RED);
			printf (" %d times each\n", philo[0].state->n_t_eat);
			i = -1;
			while (++i < philo[0].state->n_philo)
			{
				printf ("philosopher %d", philo[i].id + 1);
				printf (" total eat = %d\n", philo[i].total_eat);
			}
			return (1);
		}
	}
	return (0);
}

int	supervisor(t_philo *philo)
{
	int				time;
	int				i;

	printf("start Supervisor\n");
	while (1)
	{
		i = -1;
		while (++i < philo[0].state->n_philo)
		{
			time = get_timestamp() - philo[i].state->time;
			if ((time - philo[i].last_eat) >= (int)philo[i].state->t_die
				&& philo[i].status != EATING)
			{
				philo[i].status = DEAD;
				// pthread_mutex_lock(&philo[0].state->print_lock);
				output(get_timestamp(), &philo[i], "died", RED);
				kill(philo[i].pid, SIGTERM);
				return (1);
			}
		}
		if (max_number_of_eat_check(philo))
			return (1);
	}
	return (1);
}
