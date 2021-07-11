/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:43:00 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/11 14:43:18 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	output(long time, t_philo *philo, char *msg, char *color)
{
	int			id;
	uint64_t	tm;

	id = philo->id + 1;
	tm = time - philo->state->time;
	printf ("%s%llu Philosopher %d %s\n", color, tm, id, msg);
}