# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vludan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 15:00:01 by vludan            #+#    #+#              #
#    Updated: 2018/02/07 12:50:38 by vludan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_ls.c ft_convers.c ft_memchr.c ft_memalloc.c ft_strcpy.c ft_strlen.c\
	  ft_strcmp.c ft_strjoin.c ft_ls_lst.c ls_lst_main.c ft_intlen.c\
	  ls_optfunct.c ft_strncpy.c ls_usage.c
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
