/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:51:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/11 11:09:49 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_args(int len, char **argv, t_state *state)
{
	if (len != 5 && len != 6)
		return (1);
	state->n_philo = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (state->n_philo == 0 || state->t_die == 0
		|| state->t_eat == 0 || state->t_sleep == 0)
		return (1);
	if (len == 6)
	{
		state->n_t_eat = ft_atoi(argv[5]);
		if (state->n_t_eat == 0)
			return (1);
	}
	else
		state->n_t_eat = -1;
	return (0);
}
