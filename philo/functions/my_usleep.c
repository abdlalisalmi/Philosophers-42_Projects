/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 08:41:02 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/07 13:24:06 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	my_usleep(uint64_t time)
{
	u_int64_t	microseconds;
	u_int64_t	current_time;
	u_int64_t	looping_time;

	looping_time = 40;
	microseconds = (time - looping_time) * 1000;
	usleep(microseconds);
	current_time = get_timestamp();
	while (get_timestamp() - current_time < looping_time)
	{
	}
}
