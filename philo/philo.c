/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/05 16:00:00 by aes-salm         ###   ########.fr       */
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

int	get_args(int len, char **argv, t_args *args)
{
	if (len != 5 && len != 6)
		return (1);
	args->n_philo = ft_atoi(argv[1]);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	if (len == 6)
		args->n_t_eat = ft_atoi(argv[5]);
	else
		args->n_t_eat = -1;
	return (0);
}

void	*supervisor(void *parm)
{
	t_args			*args;
	uint64_t		time;
	int				i;

	args = (t_args *)parm;
	while (1)
	{
		i = -1;
		while (++i < args->n_philo)
		{
			time = get_timestamp() - args->time;
			if ((time - args->philosophers[i].last_eat) > args->t_die && args->philosophers[i].status != EATING)
			{
				output(get_timestamp(), args, "died");
				//printf("philo = %d, time = %lld, last eat = %lld\n", i+1, args.t_die, args.philosophers[i].last_eat);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (NULL);
}

void *philosopher(void *parm)
{
	t_args		*args;

	args = (t_args *)parm;
    while (1)
	{
		take_forks(args);
		start_eating(args);
		start_sleeping(args);
		start_thinking(args);
	}
	return (NULL);
}

int	main(int len, char **argv)
{
	t_args		*args;
	pthread_t	*tid;
	pthread_t	stid;
	int 		i;


	args = malloc(sizeof(t_args));

	if (get_args(len, argv, args))
		usage();
	tid = malloc(sizeof(pthread_t) * args->n_philo);
	args->philosophers = malloc(sizeof(t_philo) * args->n_philo);

	args->time = get_timestamp();


	 if (pthread_mutex_init(&args->lock, NULL) != 0)
        exit_program("mutex init failed", EXIT_FAILURE);

  	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
    i = -1;
    while (++i < args->n_philo)
        if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			exit_program("mutex init failed", EXIT_FAILURE);

	i = -1;
    while (++i < args->n_philo)
	{
		args->philo_number = i;
        pthread_create(&tid[i], NULL, philosopher, (void *)args);
	}
	pthread_create(&stid, NULL, supervisor, (void *)args);

	i = -1;
    while (++i < args->n_philo)
        pthread_join(tid[i], NULL);
	pthread_join(stid, NULL);

	i = -1;
	while (++i < args->n_philo)
        pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->lock);
	return (0);
}
