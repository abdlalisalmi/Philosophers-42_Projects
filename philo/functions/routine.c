/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/06 10:18:42 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    output(long time, t_philo *philo, char *msg)
{
    printf("%llu Philosopher %d %s\n", time - philo->time, philo->id + 1, msg);
}

void	take_forks(t_philo *philo)
{
	int         left;
	int         right;
    uint64_t    time;
    pthread_mutex_t 	lock;

    if (pthread_mutex_init(&lock, NULL) != 0)
        exit_program("mutex init failed", EXIT_FAILURE);
	pthread_mutex_lock(&lock);
	right = (philo->id + 1) % philo->n_philo;
	left = philo->id;
    pthread_mutex_lock(&philo->forks->forks[right]);
    pthread_mutex_lock(&philo->forks->forks[left]);
    time = get_timestamp();
    output(time, philo, "has taken a fork");
    pthread_mutex_unlock(&lock);
}

//void    start_eating(t_philo *philo)
//{
//    int right;
//    int left;

//    right = (philo->id + 1) % philo->n_philo;
//	left = philo->id;
//    philo->philosophers[philo->id].status = EATING;
//    output(get_timestamp(), philo, "is eating");
//    philo->philosophers[philo->id].total_eat += 1;
//    usleep(philo->t_eat * 1000);
//    philo->philosophers[philo->id].last_eat = get_timestamp() - philo->time;

//    pthread_mutex_unlock(&philo->forks[right]);
//    pthread_mutex_unlock(&philo->forks[left]);
//}

//void    start_sleeping(t_philo *philo)
//{
//    philo->philosophers[philo->id].status = SLEEPING;
//    output(get_timestamp(), philo, "is sleeping");
//    usleep(philo->t_sleep * 1000);
//}

//void    start_thinking(t_philo *philo)
//{
//    philo->philosophers[philo->id].status = THINKING;
//    output(get_timestamp(), philo, "is thinking");
//}