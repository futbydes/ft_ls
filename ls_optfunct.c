/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:40:10 by vludan            #+#    #+#             */
/*   Updated: 2018/01/30 17:27:42 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ls_time(char *time)
{
	char	*temp;

	while (*time != ' ')
		time++;
	time++;
	temp = ft_memalloc(13);
	temp = ft_strncpy(temp, time, 12);
	return (temp);
}

void		ls_xattributes(t_list *lst, char *path)
{
	char	*xattr;

	xattr = 0;
	path = ls_pathmaker(path, lst->name);
	lst->f_rights[10] = (listxattr(path, xattr, 1024, 0) ? '@' : ' ');
	free(xattr);
}
