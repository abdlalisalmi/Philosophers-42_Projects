/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:36:17 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 15:52:26 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define EATING 1
# define THINKING 2
# define SLEEPING 3

# define FREEFORK 0
# define BUSYFORK 1

typedef struct s_philo
{
	int				id;
	int				total_eat;
	int				last_eat;
	pthread_mutex_t	lock;
}				t_philo;

typedef struct s_args
{
	int			n_philo;
	uint64_t	t_die;
	uint64_t	t_eat;
	uint64_t	t_sleep;
	int			n_t_eat;
	uint64_t	time;

	t_philo		*philosophers;
	int 		*forks;
	pthread_mutex_t lock;
	pthread_mutex_t output_lock;
	
}				t_args;
t_args			g_args;

uint64_t	get_timestamp(void);
void	exit_program(char *msg, int code);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void    output(long time, int philo_id, char *msg);

int		take_forks(int philo_number);
void    start_eating(uint64_t time, int philo_number, int right, int left);
void    start_sleeping(int philo_number);
void    start_thinking(int philo_number);

#endif
 