/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:47:16 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/03 10:47:35 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_timestamp(void)
{
	long			milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL); // get current time
	milliseconds = time.tv_sec  * 1000LL + time.tv_usec / 1000; // calculate milliseconds
	return (milliseconds);
}
