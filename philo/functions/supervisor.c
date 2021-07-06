/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/05 19:43:21 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*supervisor(void *parm)
{
	t_args			*args;
	uint64_t		time;
	int				i;

	args = (t_args *)parm;
	while (1)
	{
		i = -1;
		while (++i < args->n_philo)
		{
			time = get_timestamp() - args->time;
			if ((time - args->philosophers[i].last_eat) > args->t_die && args->philosophers[i].status != EATING)
			{
				output(get_timestamp(), args, "died");
				printf("philo = %d, time = %lld, last eat = %lld\n", i+1, args->t_die, args->philosophers[i].last_eat);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (NULL);
}
