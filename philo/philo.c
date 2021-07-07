/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/07 09:46:20 by aes-salm         ###   ########.fr       */
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

void *philosopher(void *parm)
{
	t_philo		*philo;

	philo = (t_philo *)parm;
     while (1)
	 {
	 	take_forks(philo);
	 	start_eating(philo);
	 	start_sleeping(philo);
	 	start_thinking(philo);
	 }
	return (NULL);
}

int	main(int len, char **argv)
{
	t_philo		*philo;
	t_forks		forks;
	pthread_t	*tid;
	pthread_t	stid;
	int 		i;


	philo = malloc(sizeof(t_philo) * 200);
	if (get_args(len, argv, philo))
		usage();
	// setup the forks
	forks.forks = malloc(sizeof(pthread_mutex_t) * philo[0].n_philo);
	i = -1;
	while (++i < philo[0].n_philo)
	{
		if (pthread_mutex_init(&forks.forks[i], NULL) != 0)
			exit_program("mutex init failed", EXIT_FAILURE);
		philo[i].forks = &forks;
	}

	tid = malloc(sizeof(pthread_t) * philo[0].n_philo);

	i = -1;
    while (++i < philo[0].n_philo)
	{
		philo[i].time = get_timestamp();
		philo[i].id = i;
	}

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


	i = -1;
    while (++i < philo[0].n_philo)
        pthread_mutex_destroy(&forks.forks[i]);

	return (0);
}
