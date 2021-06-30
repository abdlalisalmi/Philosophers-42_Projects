# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 11:36:20 by aes-salm          #+#    #+#              #
#    Updated: 2021/06/30 09:43:00 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRCS	= 	functions/exit_program.c\
			functions/ft_atoi.c\
			functions/ft_strlen.c\


$(NAME) :	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o
			@ $(CC) $(FLAGS) philo.c $(NAME) -o philo

all		:	$(NAME)

clean	:
			@ rm -rf *.o

fclean	:	clean
			@ rm -rf $(NAME) philo
			
re		:	fclean all

test	:	re
			@ rm -rf philo.a *.o
