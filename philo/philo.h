/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:36:17 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/06 12:55:37 by aes-salm         ###   ########.fr       */
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

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define WHITE "\033[0;37m"

# define EATING 1
# define THINKING 2
# define SLEEPING 3

typedef struct s_forks
{
	pthread_mutex_t		*forks;
	
}						t_forks;

typedef struct s_philo
{
	int					n_philo;
	uint64_t			time;
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_sleep;
	int					n_t_eat;

	int					id;
	int					status;
	int					total_eat;
	uint64_t			last_eat;

	t_forks				*forks;
}						t_philo;


uint64_t	get_timestamp(void);
void		exit_program(char *msg, int code);
 void		output(long time, t_philo *philo, char *msg, char *color);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);

 void		*supervisor(void *parm);
 void		take_forks(t_philo *philo);
 void		start_eating(t_philo *philo);
 void		start_sleeping(t_philo *philo);
 void		start_thinking(t_philo *philo);

#endif
 