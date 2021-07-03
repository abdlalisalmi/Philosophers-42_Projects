/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:47:16 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 15:21:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	get_timestamp(void)
{
	uint64_t		milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL); // get current time
	milliseconds = time.tv_sec  * 1000LL + time.tv_usec / 1000; // calculate milliseconds
	return (milliseconds);
}
