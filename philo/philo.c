/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/12 21:25:18 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage(void)
{
	printf("\n\033[0;31mUsage:\n");
	printf("\t$> ./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
}

void	*philosopher(void *parm)
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

void	launch_simulation(t_state state, t_philo *philo)
{
	int			i;
	pthread_t	stid;

	i = -1;
	while (++i < state.n_philo)
		pthread_create(&philo[i].tid, NULL, philosopher, (void *)&philo[i]);
	pthread_create(&stid, NULL, supervisor, (void *)philo);
	pthread_join(stid, NULL);
	i = -1;
	while (++i < state.n_philo)
		pthread_mutex_destroy(&philo[0].state->forks[i]);
}

void	init_mutex(t_state *state, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < state->n_philo)
	{
		pthread_mutex_init(&state->forks[i], NULL);
		pthread_mutex_init(&philo[0].eat_lock, NULL);
	}
	pthread_mutex_init(&state->print_lock, NULL);
}

int	main(int len, char **argv)
{
	t_philo		*philo;
	t_state		state;
	int			i;

	if (get_args(len, argv, &state))
		usage();
	else
	{
		philo = malloc(sizeof(t_philo) * state.n_philo);
		state.forks = malloc(sizeof(pthread_mutex_t) * state.n_philo);
		i = -1;
		state.time = get_timestamp();
		while (++i < state.n_philo)
		{
			philo[i].state = &state;
			philo[i].id = i;
			philo[i].last_eat = 0;
			philo[i].total_eat = 0;
		}
		init_mutex(&state, philo);
		launch_simulation(state, philo);
		free(state.forks);
	}
	return (0);
}
