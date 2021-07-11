/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/11 14:16:34 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	usage(void)
{
	printf("\n\033[0;31mUsage:\n");
	printf("\t$> ./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
}

void	philosopher(t_philo *philo)
{
	while (philo->status != DEAD)
	{
		printf("Philosppher %d\n", philo->id);
		sleep(5);
		//take_forks(philo);
		//start_eating(philo);
		//start_sleeping(philo);
		//start_thinking(philo);
	}
	//return (NULL);
}

void	launch_simulation(t_state state, t_philo *philo)
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
		i = -1;
		state.time = get_timestamp();
		while (++i < state.n_philo)
		{
			philo[i].state = &state;
			philo[i].id = i;
		}
		launch_simulation(state, philo);
	}
	return (0);
}
