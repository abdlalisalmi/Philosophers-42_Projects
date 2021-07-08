/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/08 13:27:23 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	output(long time, t_philo *philo, char *msg, char *color)
{
	int			id;
	uint64_t	tm;

	id = philo->id + 1;
	tm = time - philo->time;
	printf ("%s%llu Philosopher %d %s\n", color, tm, id, msg);
}

void	take_forks(t_philo *philo)
{
	int					left;
	int					right;
	uint64_t			time;
	pthread_mutex_t		lock;

	if (pthread_mutex_init(&lock, NULL) != 0)
		exit_program("mutex init failed", EXIT_FAILURE);
	pthread_mutex_lock(&lock);
	right = (philo->id + 1) % philo->n_philo;
	left = philo->id;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->forks->forks[right]);
		pthread_mutex_lock(&philo->forks->forks[left]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks->forks[left]);
		pthread_mutex_lock(&philo->forks->forks[right]);
	}
	time = get_timestamp();
	output(time, philo, "has taken a fork", GREEN);
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
}

void	start_eating(t_philo *philo)
{
	int	right;
	int	left;

	right = (philo->id + 1) % philo->n_philo;
	left = philo->id;
	philo->status = EATING;
	output(get_timestamp(), philo, "is eating", GREEN);
	philo->total_eat += 1;
	my_usleep(philo->t_eat);
	philo->last_eat = get_timestamp() - philo->time;
	pthread_mutex_unlock(&philo->forks->forks[right]);
	pthread_mutex_unlock(&philo->forks->forks[left]);
}

void	start_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	output(get_timestamp(), philo, "is sleeping", YELLOW);
	my_usleep(philo->t_sleep);
}

void	start_thinking(t_philo *philo)
{
	philo->status = THINKING;
	output(get_timestamp(), philo, "is thinking", WHITE);
}
