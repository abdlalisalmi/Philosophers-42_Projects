# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 11:36:20 by aes-salm          #+#    #+#              #
#    Updated: 2021/06/26 11:58:58 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRCS	= functions/test.c


$(NAME) :	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o
			@ $(CC) $(FLAGS) main.c $(NAME) -o philo -g3 -fsanitize=address

all		:	$(NAME)

clean	:
			@ rm -rf *.o

fclean	:	clean
			@ rm -rf $(NAME) philo
			
re		:	fclean all