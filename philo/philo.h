/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:36:17 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/11 18:32:56 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define WHITE "\033[0;37m"

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4

typedef struct s_state
{
	int					n_philo;
	uint64_t			time;
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_sleep;
	int					n_t_eat;

	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
}						t_state;

typedef struct s_philo
{
	int					id;
	int					status;
	int					total_eat;
	int					last_eat;
	pthread_mutex_t		lock;
	pthread_t			tid;

	t_state				*state;
}						t_philo;

uint64_t	get_timestamp(void);
int			get_args(int len, char **argv, t_state *state);
void		my_usleep(uint64_t time);
void		exit_program(char *msg, int code);
void		output(long time, t_philo *philo, char *msg, char *color);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);

int		supervisor(t_philo *philo);
void		take_forks(t_philo *philo);
void		start_eating(t_philo *philo);
void		start_sleeping(t_philo *philo);
void		start_thinking(t_philo *philo);

#endif
