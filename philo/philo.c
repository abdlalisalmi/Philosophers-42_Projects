/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:44:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/02 20:58:47 by aes-salm         ###   ########.fr       */
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
	g_args.t_die = ft_atoi(args[2]) * 1000;
	g_args.t_eat = ft_atoi(args[3]) * 1000;
	g_args.t_sleep = ft_atoi(args[4]) * 1000;
	if (len == 6)
		g_args.n_t_eat = ft_atoi(args[5]);
	else
		g_args.n_t_eat = -1;
	return (0);
}

long	get_timestamp(void)
{
	long			milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL); // get current time
	milliseconds = time.tv_sec  * 1000LL + time.tv_usec / 1000; // calculate milliseconds
	return (milliseconds);
}

void	take_fork()
{
	
}

void *philospher(void *id)
{
	int philosopher_number = *((int*)id);
	int left;
	int right;
    while (1)
	{
		// check n pick right Chopstick
		right = (philosopher_number + 1) % g_args.n_philo;
		if(g_args.chopsticks[right] == 1)
			continue;

		// Check n pick left chopstick
		left = philosopher_number;
		if(g_args.chopsticks[left] == 1)
			continue;            
            
		// int* i = num;
        printf("%ld Philosopher %d has taken %d and %d fork\n", get_timestamp(), philosopher_number, right, left);

        sleep(5);
		// EXIT Section : Free the Chopsticks
		g_args.chopsticks[philosopher_number] = 0;
		g_args.chopsticks[(philosopher_number+1) % g_args.n_philo] = 0;

        // printf("%ld X %d has taken a fork\n", get_timestamp(), philosopher_number);
        // printf("%ld X %d is eating\n", get_timestamp(), philosopher_number);
        // printf("%ld X %d is sleeping\n", get_timestamp(), philosopher_number);
        // printf("%ld X %d is thinking\n", get_timestamp(), philosopher_number);
        // printf("%ld X %d died\n", get_timestamp(), philosopher_number);
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

	pthread_t tid[g_args.n_philo];
	int philosophers[g_args.n_philo];
	int i;


	// Setting the Philosopher Numbers
	i = -1;
    while (++i < g_args.n_philo)
        philosophers[i] = i;


  // Setting the state of all Chopsticks as 0
  	g_args.chopsticks = malloc(sizeof(int) * g_args.n_philo);
    i = -1;
    while (++i < g_args.n_philo)
        g_args.chopsticks[i] = 0;


	// create philosopher thread
	i = -1;
    while (++i < g_args.n_philo)
        pthread_create(&tid[i], NULL, philospher, (void*)&philosophers[i]);


	// Wait equivalent
	i = -1;
    while (++i < g_args.n_philo)
        pthread_join(tid[i], NULL);

	return (0);
}