/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/30 09:44:46 by aes-salm         ###   ########.fr       */
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

long	current_timestamp(void)
{
	long			milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL); // get current time
	milliseconds = time.tv_sec  * 1000LL + time.tv_usec / 1000; // calculate milliseconds
	return (milliseconds);
}

void *philospher(void *num)
{
 
    while (1)
	{
        sleep(1);
        printf("Philosopher %d take fork\n", (int)num);
        // sleep(1);
        // printf("Philosopher %d put fork\n", (int)num);
    }
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

	// printf("milliseconds: %ld\n", current_timestamp());


	// int phil[5] = { 0, 1, 2, 3, 4 };
	// pthread_t thread_id[5];

	// for (int i = 0; i < 5; i++)
	// {
    //     // create philosopher thread
    //     pthread_create(&thread_id[i], NULL, philospher, &phil[i]);
    //     printf("Philosopher %d is thinking\n", i + 1);
    // }
	// for (int i = 0; i < 5; i++)
    //     pthread_join(thread_id[i], NULL);

	return (0);
}