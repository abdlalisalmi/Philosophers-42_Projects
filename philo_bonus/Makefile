# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 11:36:20 by aes-salm          #+#    #+#              #
#    Updated: 2021/07/11 14:11:03 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	philo_bonus.a
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
SRCS	=	functions/get_args.c\
			functions/ft_atoi.c\
			functions/get_timestamp.c\



$(NAME) :	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o
			@ $(CC) $(FLAGS) philo_bonus.c $(NAME) -o philo_bonus -g

all		:	$(NAME)

clean	:
			@ rm -rf *.o

fclean	:	clean
			@ rm -rf $(NAME) philo_bonus
			
re		:	fclean all

test	:	re
			@ rm -rf philo_bonus.a *.o
