/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/29 17:30:47 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	usage(void)
{
	printf("\nUsage:\n");
	printf("\t> ./philo number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n");
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

long	current_timestamp(void)
{
	long			milliseconds;
	struct timeval	te;

	gettimeofday(&te, NULL); // get current time
	milliseconds = te.tv_sec  * 1000LL + te.tv_usec / 1000; // calculate milliseconds
	return (milliseconds);
}

int	main(int len, char **args)
{
	if (get_args(len, args))
		usage();
		
	// printf("number_of_philosophers: %d\n", g_args.n_philo);
	// printf("time_to_die: %d\n", g_args.t_die);
	// printf("time_to_eat: %d\n", g_args.t_eat);
	// printf("time_to_sleep: %d\n", g_args.t_sleep);
	// printf("number_of_times_each_philosopher_must_eat: %d\n", g_args.n_t_eat);

	printf("milliseconds: %ld\n", current_timestamp());
	
	return (0);
}