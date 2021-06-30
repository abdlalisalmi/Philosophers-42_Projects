/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:36:17 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/29 18:53:35 by aes-salm         ###   ########.fr       */
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


typedef struct s_args
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_t_eat;
}				t_args;
t_args			g_args;

void	exit_program(char *msg, int code);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

#endif
 