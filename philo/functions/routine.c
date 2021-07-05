/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/05 16:03:38 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    output(long time, t_args *args, char *msg)
{
    printf("%llu Philosopher %d %s\n", time - args->time, args->philo_number + 1, msg);
}

void	take_forks(t_args *args)
{
	int         left;
	int         right;
    uint64_t    time;

	pthread_mutex_lock(&args->lock);
	right = (args->philo_number + 1) % args->n_philo;
	left = args->philo_number;
    pthread_mutex_lock(&args->forks[right]);
    pthread_mutex_lock(&args->forks[left]);
    time = get_timestamp();
    output(time, args, "has taken a fork");
    pthread_mutex_unlock(&args->lock);
    //return (1);
	//if(g_args.forks[right] == FREEFORK && g_args.forks[left] == FREEFORK && !(g_args.n_philo <= 1))
    //{
    //    time = get_timestamp();
	//	output(time, philo_number, "has taken a fork");
    //    g_args.forks[right] = BUSYFORK;
    //    g_args.forks[left] = BUSYFORK;
	//    pthread_mutex_unlock(&g_args.lock);
    //    return (1);
    //}
    //pthread_mutex_unlock(&g_args.lock);
	//return (0);
}

void    start_eating(t_args *args)
{
    int right;
    int left;

    right = (args->philo_number + 1) % args->n_philo;
	left = args->philo_number;
    args->philosophers[args->philo_number].status = EATING;
    output(get_timestamp(), args, "is eating");
    args->philosophers[args->philo_number].total_eat += 1;
    usleep(args->t_eat * 1000);
    args->philosophers[args->philo_number].last_eat = get_timestamp() - args->time;

    pthread_mutex_unlock(&args->forks[right]);
    pthread_mutex_unlock(&args->forks[left]);
}

void    start_sleeping(t_args *args)
{
    args->philosophers[args->philo_number].status = SLEEPING;
    output(get_timestamp(), args, "is sleeping");
    usleep(args->t_sleep * 1000);
}

void    start_thinking(t_args *args)
{
    args->philosophers[args->philo_number].status = THINKING;
    output(get_timestamp(), args, "is thinking");
}