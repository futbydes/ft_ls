/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:38:02 by vludan            #+#    #+#             */
/*   Updated: 2017/12/05 14:56:48 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

t_lst		*ft_lst(int fd, t_lst *current)
{
	t_lst	*new;
	t_lst	*head;
	t_lst	*temp;

	head = current;
	while (current != 0)
	{
		if (current->ds == fd)
			return (current);
		if (current->next != 0 && current->next->ds == fd)
		{
			temp = current;
			current = current->next;
			temp->next = temp->next->next;
			current->next = head;
			return (current);
		}
		current = current->next;
	}
	new = (t_lst*)malloc(sizeof(t_lst));
	new->buff = ft_memalloc(BUFF_SIZE + 1);
	new->ds = fd;
	new->next = head;
	return (new);
}

char		*ft_realloc(char **line, char *buff)
{
	int		x;
	int		y;
	char	*new;

	x = 0;
	y = ft_strlen(*line);
	while (buff[x] != '\n' && x != BUFF_SIZE && buff[x] != 0)
		x++;
	new = ft_strnew(x + y);
	ft_strcpy(new, *line);
	ft_strclr(*line);
	if (line != 0)
		free(*line);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	int				bread;
	char			*arr;

	lst = ft_lst(fd, lst);
	if ((lst->buff == 0 && ((read(fd, lst->buff, BUFF_SIZE)) <= 0))
			|| line == 0 || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	arr = ft_memalloc(BUFF_SIZE + 1);
	*line = arr;
	while (ft_memccpy(arr, lst->buff, '\n', BUFF_SIZE) == 0)
	{
		ft_bzero(lst->buff, BUFF_SIZE);
		if ((bread = read(fd, lst->buff, BUFF_SIZE)) <= 0)
		{
			if (bread < 0)
				return (-1);
			return (1) <= ft_strlen(*line);
		}
		*line = ft_realloc(line, lst->buff);
		arr = *line + ft_strlen(*line);
	}
	ft_bzero(ft_memchr(*line, '\n', ft_strlen(*line)), 1);
	ft_memmove(lst->buff, ft_memchr(lst->buff, '\n', BUFF_SIZE) + 1, BUFF_SIZE);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	**line;
	int		x;

	x = -1;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	line = malloc(1000);
	while (x != 0)
	{
		if (x == -1)
			return (0);
		printf("RETURN:%d\n", x = get_next_line(102, line));
		printf("RETURN:%s\n", *line);
	}
	return (0);
}
