# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vludan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 15:00:01 by vludan            #+#    #+#              #
#    Updated: 2018/01/26 15:51:56 by vludan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_ls.c ft_convers.c ft_memchr.c ft_memalloc.c ft_strcpy.c ft_strlen.c\
	  ft_strcmp.c ft_ls_lst.c ft_ls_lst2.c
OBJ = $(SRC:.c=.o)
INCLUDES = ft_ls.h
NAME = ft_ls
CFLAGS = -Wall -Werror -Wextra
CC = gcc

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
