/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:12:28 by vludan            #+#    #+#             */
/*   Updated: 2017/12/04 13:55:25 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>

typedef struct		s_lst
{
	int				ds;
	char			*buff;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
