/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:36:17 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 13:41:35 by aes-salm         ###   ########.fr       */
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
	pthread_mutex_t	lock;
}				t_philo;

typedef struct s_args
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_t_eat;

	t_philo		*philosophers;
	int 		*forks;
	pthread_mutex_t lock;
	
}				t_args;
t_args			g_args;

long	get_timestamp(void);
void	exit_program(char *msg, int code);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

int		take_forks(int philo_number);
void    start_eating(int philo_number, int right, int left);
void    start_sleeping(int philo_number);
void    start_thinking(int philo_number);

#endif
 