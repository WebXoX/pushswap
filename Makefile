# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:04:44 by jperinch          #+#    #+#              #
#    Updated: 2023/06/15 15:51:02 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	ft_atoi.c               push_swap.c             sorter.c        ft_lst.c                 \
		string_function.c               ft_lstclear.c           push_utils.c            wordcheck.c \
		freed.c                 lst_split.c             push_utils1.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 
CC = gcc 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)


all: $(NAME)


clean:
	rm -rf *.o 

fclean:
	rm -f $(NAME) *.o 

re:     fclean all