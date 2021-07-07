/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/07 20:40:22 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage(void)
{
	printf("\n\033[0;31mUsage:\n");
	printf("\t$> ./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
	exit(EXIT_FAILURE);
}

void	*philosopher(void *parm)
{
	t_philo		*philo;

	philo = (t_philo *)parm;
	while (1 && philo->status != DEAD)
	{
		take_forks(philo);
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}

void	launch_simulation(t_philo *philo)
{
	int			i;
	pthread_t	*tid;
	pthread_t	stid;

	tid = malloc(sizeof(pthread_t) * philo[0].n_philo);
	i = -1;
	while (++i < philo[0].n_philo)
		pthread_create(&tid[i], NULL, philosopher, (void *)&philo[i]);
	pthread_create(&stid, NULL, supervisor, (void *)philo);
	i = -1;
	while (++i < philo[0].n_philo)
		pthread_join(tid[i], NULL);
	pthread_join(stid, NULL);
	i = -1;
	while (++i < philo[0].n_philo)
		pthread_mutex_destroy(&philo[0].forks->forks[i]);
}

int	main(int len, char **argv)
{
	t_philo		*philo;
	t_forks		forks;
	int			i;

	philo = malloc(sizeof(t_philo) * 200);
	if (get_args(len, argv, philo))
		usage();
	forks.forks = malloc(sizeof(pthread_mutex_t) * philo[0].n_philo);
	i = -1;
	while (++i < philo[0].n_philo)
	{
		if (pthread_mutex_init(&forks.forks[i], NULL) != 0)
			exit_program("mutex init failed", EXIT_FAILURE);
		philo[i].forks = &forks;
	}
	i = -1;
	while (++i < philo[0].n_philo)
	{
		philo[i].time = get_timestamp();
		philo[i].id = i;
	}
	launch_simulation(philo);
	return (0);
}
