/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:40:10 by vludan            #+#    #+#             */
/*   Updated: 2018/01/31 20:15:21 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ls_time(char *time)
{
	char			*temp;

	while (*time != ' ')
		time++;
	time++;
	temp = ft_memalloc(13);
	temp = ft_strncpy(temp, time, 12);
	return (temp);
}

void				ls_xattributes(t_list *lst, char *path)
{
	char			*xattr;
	char			*buf;

	xattr = ft_memalloc(255);
	buf = ft_memalloc(255);
	if (S_ISLNK(lst->st_mode)) //non-realized links xattr
		readlink(path, buf, 255);
	lst->f_rights[10] = (listxattr((buf[0] != 0 ? buf : path), xattr, 1024, 0) > 0 ? '@' : ' ');
	free(xattr);
	free(buf);
}

void				ls_d_conv(char *path, t_flags *flg)
{
	struct stat		*buf;
	t_list			*lst;

	lst = 0;
	buf = ft_memalloc(sizeof(struct stat));
	if (lstat(path, buf) < 0)
		perror("Error: ");
	flg->path_in = path;
	lst = ls_lstnew(lst, path, buf, flg);
	ls_lstprint(lst, flg, path);
	free(buf);
}
