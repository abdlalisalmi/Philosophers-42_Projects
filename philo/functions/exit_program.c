/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:03:01 by aes-salm          #+#    #+#             */
/*   Updated: 2021/07/07 13:21:26 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	exit_program(char *msg, int code)
{
	write(2, msg, ft_strlen(msg));
	exit(code);
}
