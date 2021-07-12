/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/12 18:57:30 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *parm)
{
	t_philo		*philo;

	philo = (t_philo *)parm;
	while (1)
	{
		// printf("Philosppher %d\n", philo->total_eat);
		// philo->total_eat += 1;
		// sleep(3);
		take_forks(philo);
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}

void	philosopher(t_philo *philo)
{
	pthread_create(&philo->tid, NULL, routine, (void *)philo);
	pthread_join(philo->tid, NULL);
	// pthread_create(&philo.stid, NULL, supervisor, (void *)philo);
	// pthread_join(philo.stid, NULL);
}

int	launch_simulation(t_state state, t_philo *philo)
{
	int i;

	i = -1;
	while (++i < state.n_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			printf("Failed forking child..");
		else if (philo[i].pid == 0)
			philosopher(&philo[i]);
	}

	if (philo[0].pid > 0)
	{
		i = -1;
		while (++i < state.n_philo)
			waitpid(philo[i].pid, &philo[i].child_status, 0);
	}
	return (0);
}

int	main(int len, char **argv)
{
	t_philo		*philo;
	t_state		state;
	int			i;

	if (get_args(len, argv, &state))
	{
		printf("\n\033[0;31mUsage:\n");
		printf("\t$> ./philo number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
	}
	else
	{
		philo = malloc(sizeof(t_philo) * state.n_philo);
		i = -1;
		state.time = get_timestamp();
		while (++i < state.n_philo)
		{
			philo[i].state = &state;
			philo[i].id = i;
			philo[i].last_eat = 0;
			philo[i].total_eat = 0;
		}
		launch_simulation(state, philo);
	}
	return (0);
}
