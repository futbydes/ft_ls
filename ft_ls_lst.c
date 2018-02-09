/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:29:58 by vludan            #+#    #+#             */
/*   Updated: 2018/02/09 15:17:36 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*ls_lstnew(t_list *head, char *name, struct stat *stat,
		t_flags *flg)
{
	t_list			*lst;

	lst = ft_memalloc(sizeof(t_list));
	lst->name = ft_memalloc((int)ft_strlen(name) + 1);
	ft_strcpy(lst->name, name);
	lst->st_mode = stat->st_mode;
	lst->next = head;
	lst->time = (flg->u == 1 ? stat->st_atime : stat->st_mtime);
	flg->linesize < (int)ft_strlen(lst->name) ?
		flg->linesize = (int)ft_strlen(lst->name) : 0;
	if (flg->l == 1 || flg->g == 1)
	{
		ls_fdata(lst, stat, flg);
		flg->maxlink < lst->n_link ? flg->maxlink = lst->n_link : 0;
		flg->maxsize < lst->f_size ? flg->maxsize = lst->f_size : 0;
		flg->maxblock < lst->b_size ? flg->maxblock = lst->b_size : 0;
		flg->totalblock += lst->b_size;
	}
	return (lst);
}

void				ls_fdata_r(t_list *lst, struct stat *stat, t_flags *flg)
{
	lst->f_rights = ft_memalloc(12);
	lst->f_rights[0] = (S_ISDIR(stat->st_mode) ? 'd' : '-');
	S_ISLNK(stat->st_mode) ? lst->f_rights[0] = 'l' : 0;
	S_ISCHR(stat->st_mode) ? lst->f_rights[0] = 'c' : 0;
	S_ISBLK(stat->st_mode) ? lst->f_rights[0] = 'b' : 0;
	lst->f_rights[1] = ((stat->st_mode & S_IRUSR) ? 'r' : '-');
	lst->f_rights[2] = ((stat->st_mode & S_IWUSR) ? 'w' : '-');
	lst->f_rights[3] = ((stat->st_mode & S_IXUSR) ? 'x' : '-');
	(stat->st_mode & S_ISUID) ? lst->f_rights[3] = 'S' : 0;
	((stat->st_mode & S_IEXEC) && (stat->st_mode & S_ISUID)) ?
		lst->f_rights[3] = 's' : 0;
	lst->f_rights[4] = ((stat->st_mode & S_IRGRP) ? 'r' : '-');
	lst->f_rights[5] = ((stat->st_mode & S_IWGRP) ? 'w' : '-');
	lst->f_rights[6] = ((stat->st_mode & S_IXGRP) ? 'x' : '-');
	(stat->st_mode & S_ISGID) ? lst->f_rights[6] = 'S' : 0;
	((stat->st_mode & S_ISGID) && (stat->st_mode & S_IEXEC)) ?
		lst->f_rights[6] = 's' : 0;
	lst->f_rights[7] = ((stat->st_mode & S_IROTH) ? 'r' : '-');
	lst->f_rights[8] = ((stat->st_mode & S_IWOTH) ? 'w' : '-');
	lst->f_rights[9] = ((stat->st_mode & S_IXOTH) ? 'x' : '-');
	(S_ISVTX & stat->st_mode) ? lst->f_rights[9] = 't' : '-';
	((S_ISVTX & stat->st_mode) && (!(S_IXOTH & stat->st_mode))) ?
		lst->f_rights[9] = 'T' : '-';
	lst->f_rights[10] = (listxattr(flg->path_in, 0, 1024,
				XATTR_NOFOLLOW) > 0 ? '@' : ' ');
}

void				ls_fdata(t_list *lst, struct stat *stat, t_flags *flg)
{
	struct passwd	*passwd;
	struct group	*group;

	ls_fdata_r(lst, stat, flg);
	lst->n_link = stat->st_nlink;
	lst->f_size = stat->st_size;
	passwd = getpwuid(stat->st_uid);
	lst->u_name = ft_memalloc(ft_strlen(passwd->pw_name) + 1);
	lst->u_name = ft_strcpy(lst->u_name, passwd->pw_name);
	group = getgrgid(stat->st_gid);
	lst->gr_name = ft_memalloc(ft_strlen(group->gr_name) + 1);
	lst->gr_name = ft_strcpy(lst->gr_name, group->gr_name);
	lst->b_size = stat->st_blocks;
	if (S_ISCHR(stat->st_mode) || S_ISBLK(stat->st_mode))
	{
		lst->major = major(stat->st_rdev);
		lst->minor = minor(stat->st_rdev);
	}
}

void				ls_lstprint_a(t_list **lst, t_flags *fg, char *path,
	char *buf)
{
	fg->path_in = ls_pathmaker(path, (*lst)->name);
	if (fg->l == 1 || fg->g == 1)
	{
		ls_acl_attr(fg->path_in, 1) ? (*lst)->f_rights[10] = '+' : 0;
		fg->s == 1 ? ft_printf("%*ld ", ((int)ft_intlen(fg->maxblock)),
				(*lst)->b_size) : 0;
		ft_printf("%-*s", ((int)ft_strlen((*lst)->f_rights)), (*lst)->f_rights);
		ft_printf("%*d ", (ft_intlen(fg->maxlink) + 1), (*lst)->n_link);
		fg->g != 1 ? ft_printf("%-*s ", ((int)ft_strlen((*lst)->u_name) + 1),
				(*lst)->u_name) : 0;
		ft_printf("%-*s ", (ft_strlen((*lst)->gr_name) + 1), (*lst)->gr_name);
		if (S_ISCHR((*lst)->st_mode) || S_ISBLK((*lst)->st_mode))
		{
			ft_printf("%3d, ", (*lst)->major);
			(*lst)->minor > 255 ? ft_printf("%3x ", (*lst)->minor) :
				ft_printf("%3d ", (*lst)->minor);
		}
		else
			ft_printf("%*lld ", (ft_intlen(fg->maxsize)), (*lst)->f_size);
		ls_time(*lst, fg);
	}
	*lst = ls_lstprint_name(*lst, fg);
	if ((fg->l || fg->g) && S_ISLNK((*lst)->st_mode))
		fg->d ? readlink(path, buf, 255) : readlink(fg->path_in, buf, 255);
	(fg->l || fg->g) && S_ISLNK((*lst)->st_mode) ? ft_printf(" -> %s", buf) : 0;
}

t_list				*ls_lstprint(t_list *lst, t_flags *flg, char *path)
{
	char			*buf;
	t_list			*temp;

	buf = ft_memalloc(255);
	temp = lst;
	(flg->l || flg->g) && flg->d != 1 && lst != 0 ?
		ft_printf("total %d\n", flg->totalblock) : 0;
	while (lst != 0)
	{
		ls_lstprint_a(&lst, flg, path, buf);
		(flg->l || flg->g || flg->one) ? ft_printf("\n") : 0;
		if (lst && (flg->acl || flg->ext) && (flg->l || flg->g))
		{
			flg->acl ? ls_acl_attr(flg->path_in, 0) : 0;
			flg->ext ? ls_xattributes(flg->path_in) : 0;
		}
		lst != 0 ? lst = lst->next : 0;
		free(flg->path_in);
	}
	ls_lstfree(lst, flg, 3);
	free(buf);
	return (temp);
}
