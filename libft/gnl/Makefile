# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vludan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:10:29 by vludan            #+#    #+#              #
#    Updated: 2017/12/05 14:57:07 by vludan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c
OBJ = $(SRC:.c=.o)
INCLUDES = get_next_line.h
NAME = gnl
CFLAGS = -Wall -Werror -Wextra
CC = gcc
DIR = ../

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. $(DIR)/libft.a
clean:
	make clean -C $(DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(DIR)
	rm -f $(NAME) $(OBJ)

re: fclean all
