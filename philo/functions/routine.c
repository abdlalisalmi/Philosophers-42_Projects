/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:32:07 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/12 16:20:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	output(long time, t_philo *philo, char *msg, char *color)
{
	int			id;
	uint64_t	tm;

	id = philo->id + 1;
	tm = time - philo->state->time;
	printf ("%s%llu Philosopher %d %s\n", color, tm, id, msg);
}

void	take_forks(t_philo *philo)
{
	int					left;
	int					right;

	right = (philo->id + 1) % philo->state->n_philo;
	left = philo->id;
	if ((philo->id + 1) % 2 == 0)
	{
		pthread_mutex_lock(&philo->state->forks[right]);
		pthread_mutex_lock(&philo->state->forks[left]);
	}
	else
	{
		pthread_mutex_lock(&philo->state->forks[left]);
		pthread_mutex_lock(&philo->state->forks[right]);
	}
	pthread_mutex_lock(&philo[0].state->print_lock);
	output(get_timestamp(), philo, "has taken a fork", GREEN);
	pthread_mutex_unlock(&philo[0].state->print_lock);
}

void	start_eating(t_philo *philo)
{
	int	right;
	int	left;

	right = (philo->id + 1) % philo->state->n_philo;
	left = philo->id;
	philo->status = EATING;
	pthread_mutex_lock(&philo[0].state->print_lock);
	output(get_timestamp(), philo, "is eating", GREEN);
	pthread_mutex_unlock(&philo[0].state->print_lock);
	philo->total_eat += 1;
	my_usleep(philo->state->t_eat);
	philo->last_eat = get_timestamp() - philo->state->time;
	pthread_mutex_unlock(&philo->state->forks[right]);
	pthread_mutex_unlock(&philo->state->forks[left]);
}

void	start_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&philo[0].state->print_lock);
	output(get_timestamp(), philo, "is sleeping", YELLOW);
	pthread_mutex_unlock(&philo[0].state->print_lock);
	my_usleep(philo->state->t_sleep);
}

void	start_thinking(t_philo *philo)
{
	philo->status = THINKING;
	pthread_mutex_lock(&philo[0].state->print_lock);
	output(get_timestamp(), philo, "is thinking", WHITE);
	pthread_mutex_unlock(&philo[0].state->print_lock);
}
