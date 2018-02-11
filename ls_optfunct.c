/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:40:10 by vludan            #+#    #+#             */
/*   Updated: 2018/02/11 11:22:35 by vludan           ###   ########.fr       */
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
		ft_printf("%.7s ", f_time);
		f_time += 16;
		ft_printf("%.4s ", f_time);
	}
	else
	{
		temp = ft_memalloc(ft_strlen(f_time) + 1);
		if (flg->f_t == 1)
			temp = ft_strncpy(temp, f_time, (ft_strlen(f_time) - 1));
		else
			temp = ft_strncpy(temp, f_time, 12);
		ft_printf("%-*s ", ((int)ft_strlen(temp)), temp);
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
		ft_printf("%*s \t", ((int)ft_strlen(xattr) + 13), xattr);
		ft_printf("% ld\n", getxattr(path, xattr, 0, 255, 0, XATTR_NOFOLLOW));
		l_xatr -= ft_strlen(xattr) + 1;
		xattr += ft_strlen(xattr) + 1;
	}
	free(temp);
}

int					ls_acl_attr(char *path, int mode)
{
	acl_t			acl;
	char			*string;
	int				x;

	string = ft_memalloc(500);
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl != 0 && mode == 1)
		x = 1;
	else if (acl != 0 && mode == 0)
	{
		x = 1;
		string = acl_to_text(acl, 0);
		ft_printf(" %s", string + 8);
	}
	else
		x = 0;
	acl_free(acl);
	free(string);
	return (x);
}

void				ls_d_conv(char *path, t_flags *flg)
{
	struct stat		*buf;
	t_list			*lst;
	int				x;

	x = 0;
	lst = 0;
	flg->path_in = path;
	while (flg->path[x][0] != 0)
	{
		buf = ft_memalloc(sizeof(struct stat));
		if (lstat(flg->path[x], buf) < 0)
		{
			perror("Error: ");
			x++;
		}
		lst = ls_lstnew(lst, flg->path[x], buf, flg);
		x++;
		free(buf);
	}
	lst = ls_lstsort(lst, flg);
	lst = ls_lstprint(lst, flg, path);
	ls_lstfree(lst, flg, 1);
}

char				*ls_pathmaker(char *path, char *new_fld)
{
	char			t[2];
	char			*temp;
	char			*temp2;

	temp = 0;
	ft_strcpy(t, "/");
	if (path[(int)ft_strlen(path) - 1] == '/')
	{
		temp = ft_memalloc(ft_strlen(path) + 1);
		temp = ft_strcpy(temp, path);
	}
	else
		temp = ft_strjoin(path, t);
	temp2 = temp;
	temp = ft_strjoin(temp, new_fld);
	free(temp2);
	return (temp);
}
