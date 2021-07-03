/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 13:46:17 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    output(long time, int philo_id, char *msg)
{
    printf("%ld Philosopher %d %s\n", time, philo_id, msg);
}

void    start_eating(int philo_number, int right, int left)
{
    output(get_timestamp(), philo_number + 1, "is eating");
    usleep(g_args.t_eat);
    g_args.forks[right] = FREEFORK;
    g_args.forks[left] = FREEFORK;
}

int	take_forks(int philo_number)
{
	int left;
	int right;

	pthread_mutex_lock(&g_args.lock);
	right = (philo_number + 1) % g_args.n_philo;
	left = philo_number;
	if(g_args.forks[right] == FREEFORK && g_args.forks[left] == FREEFORK)
    {
		output(get_timestamp(), philo_number + 1, "has taken a fork");
        g_args.forks[right] = BUSYFORK;
        g_args.forks[left] = BUSYFORK;
	    pthread_mutex_unlock(&g_args.lock);
        start_eating(philo_number, right, left);
        return (1);
    }
    pthread_mutex_unlock(&g_args.lock);
	return (0);
}

void    start_sleeping(int philo_number)
{
    output(get_timestamp(), philo_number + 1, "is sleeping");
    usleep(g_args.t_sleep);
}

void    start_thinking(int philo_number)
{
    output(get_timestamp(), philo_number + 1, "is thinking");
}