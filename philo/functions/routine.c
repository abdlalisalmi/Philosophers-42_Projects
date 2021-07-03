/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 19:24:51 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    output(long time, int philo_id, char *msg)
{
    pthread_mutex_lock(&g_args.output_lock);
    printf("%llu Philosopher %d %s\n", time - g_args.time, philo_id + 1, msg);
    pthread_mutex_unlock(&g_args.output_lock);
}

void    start_eating(uint64_t time, int philo_number, int right, int left)
{
    output(time, philo_number, "is eating");
    g_args.philosophers[philo_number].total_eat += 1;
    usleep(g_args.t_eat * 1000);
    g_args.philosophers[philo_number].last_eat = get_timestamp() - g_args.time;
    g_args.forks[right] = FREEFORK;
    g_args.forks[left] = FREEFORK;
}

int	take_forks(int philo_number)
{
	int         left;
	int         right;
    uint64_t    time;

	pthread_mutex_lock(&g_args.lock);
	right = (philo_number + 1) % g_args.n_philo;
	left = philo_number;
	if(g_args.forks[right] == FREEFORK && g_args.forks[left] == FREEFORK && !(g_args.n_philo <= 1))
    {
        time = get_timestamp();
		output(time, philo_number, "has taken a fork");
        g_args.forks[right] = BUSYFORK;
        g_args.forks[left] = BUSYFORK;
	    pthread_mutex_unlock(&g_args.lock);
        start_eating(time, philo_number, right, left);
        return (1);
    }
    pthread_mutex_unlock(&g_args.lock);
	return (0);
}

void    start_sleeping(int philo_number)
{
    output(get_timestamp(), philo_number, "is sleeping");
    usleep(g_args.t_sleep * 1000);
}

void    start_thinking(int philo_number)
{
    output(get_timestamp(), philo_number, "is thinking");
}