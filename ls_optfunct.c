/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:40:10 by vludan            #+#    #+#             */
/*   Updated: 2018/02/07 16:08:16 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ls_time(t_list *lst, t_flags *flg)
{
	char			*temp;
	char			*f_time;
	time_t			tloc;

	tloc = time(&tloc);
	f_time = ctime(&lst->time);
	while (*f_time != ' ')
		f_time++;
	f_time++;
	if ((tloc - 15811200) > lst->time)
	{
		printf("%.7s ", f_time);
		f_time += 16;
		printf("%.4s ", f_time);
	}
	else
	{
		temp = ft_memalloc(ft_strlen(f_time) + 1);
		if (flg->T == 1)
			temp = ft_strncpy(temp, f_time, (ft_strlen(f_time) - 1));
		else
			temp = ft_strncpy(temp, f_time, 12);
		printf("%-*s ", ((int)ft_strlen(temp)), temp);
		free(temp);
	}
}

void				ls_xattributes(char *path)
{
	int				l_xatr;
	char			*xattr;
	char			*temp;

	xattr = ft_memalloc(255);
	temp = xattr;
	l_xatr = listxattr(path, xattr, 1024, XATTR_NOFOLLOW);
	while (l_xatr > 0)
	{
		printf("%*s \t", ((int)ft_strlen(xattr) + 13), xattr);
		printf("% ld\n", getxattr(path, xattr, 0, 255, 0, XATTR_NOFOLLOW));
		l_xatr -= ft_strlen(xattr) + 1;
		xattr += ft_strlen(xattr) + 1;
	}
	free(temp);
}

void				ls_d_conv(char *path, t_flags *flg)
{
	struct stat		*buf;
	t_list			*lst;

	lst = 0;
	flg->d = 1;
	buf = ft_memalloc(sizeof(struct stat));
	if (lstat(path, buf) < 0)
		perror("Error: ");
	flg->path_in = path;
	lst = ls_lstnew(lst, path, buf, flg);
	lst = ls_lstprint(lst, flg, path);
	free(buf);
	ls_lstfree(lst);
}

char			*ls_pathmaker(char *path, char *new_fld)
{
	char		t[2];
	char		*temp;

	temp = 0;
	ft_strcpy(t, "/");
	temp = ft_strjoin(path, t);
//	if (!(ft_memchr(path, '/', ft_strlen(path))))
//		free(path);
	temp = ft_strjoin(temp, new_fld);
	return (temp);
}
