/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 08:41:02 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/12 18:52:37 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	my_usleep(uint64_t time)
{
	u_int64_t	microseconds;
	u_int64_t	current_time;
	u_int64_t	looping_time;

	looping_time = (time / 5) + (time / 5);
	microseconds = (time - looping_time) * 1000;
	usleep(microseconds);
	current_time = get_timestamp();
	while (get_timestamp() - current_time < looping_time)
	{
	}
}
