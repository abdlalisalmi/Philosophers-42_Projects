/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 19:12:49 by aes-salm         ###   ########.fr       */
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

int	get_args(int len, char **args)
{
	if (len != 5 && len != 6)
		return (1);
	g_args.n_philo = ft_atoi(args[1]);
	g_args.t_die = ft_atoi(args[2]);
	g_args.t_eat = ft_atoi(args[3]);
	g_args.t_sleep = ft_atoi(args[4]);
	if (len == 6)
		g_args.n_t_eat = ft_atoi(args[5]);
	else
		g_args.n_t_eat = -1;
	return (0);
}

void	supervisor(void)
{
	int	i;
	uint64_t time;

	i = -1;
    while (++i < g_args.n_philo)
	{
		time = get_timestamp() - g_args.time;
		if ((time - g_args.philosophers[i].last_eat) > g_args.t_die)
		{
			output(get_timestamp(), i, "died");
			printf("philo = %d time = %lld last eat = %lld\n", i+1, g_args.t_die, g_args.philosophers[i].last_eat);
			exit(EXIT_FAILURE);
		}
	}
}

void *philosopher(void *id)
{
	int philo_number = *((int*)id);

    while (1)
	{
		supervisor();
        if (!take_forks(philo_number))
			continue;
		start_sleeping(philo_number);
		start_thinking(philo_number);
    }
}

int	main(int len, char **args)
{
	pthread_t *tid;
	int i;


	if (get_args(len, args))
		usage();


	tid = malloc(sizeof(pthread_t) * g_args.n_philo);
	g_args.philosophers = malloc(sizeof(t_philo) * g_args.n_philo);

	g_args.time = get_timestamp();

	 if (pthread_mutex_init(&g_args.lock, NULL) != 0)
        exit_program("mutex init failed", EXIT_FAILURE);


	// Setting the Philosopher Numbers
	i = -1;
    while (++i < g_args.n_philo)
        g_args.philosophers[i].id = i;


  // Setting the state of all forks as 0
  	g_args.forks = malloc(sizeof(int) * g_args.n_philo);
    i = -1;
    while (++i < g_args.n_philo)
        g_args.forks[i] = 0;


	// create philosopher thread
	i = -1;
    while (++i < g_args.n_philo)
        pthread_create(&tid[i], NULL, philosopher, (void*)&g_args.philosophers[i].id);


	// Wait equivalent
	i = -1;
    while (++i < g_args.n_philo)
        pthread_join(tid[i], NULL);

	pthread_mutex_destroy(&g_args.lock);

	return (0);
}
