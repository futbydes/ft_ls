/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:29:58 by vludan            #+#    #+#             */
/*   Updated: 2018/02/02 16:31:10 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ls_lstsort(t_list *head, t_flags *flg)
{
	t_list		*sort;

	sort = 0;
	if (flg->f == 1)
		sort = head;
	else
		sort = ls_lstbubsort(&head, 0);
	if (flg->t == 1 && flg->f != 1)
		sort = ls_lstbubsort(&head, 1);
	ls_lstrev(&sort);
	if (flg->r == 1 && flg->f != 1)
		ls_lstrev(&sort);
	return (sort);
}

t_list			*ls_lstnew(t_list *head, char *name, struct stat *stat,
		t_flags *flg)
{
	t_list	*lst;

	lst = ft_memalloc(sizeof(t_list));
	lst->name = ft_memalloc((int)ft_strlen(name) + 1);
	ft_strcpy(lst->name, name);
	lst->st_mode = stat->st_mode;
	lst->next = head;
	lst->time = (flg->u == 1 ? stat->st_atime : stat->st_mtime);
	if (flg->l == 1 || flg->g == 1)
	{
		ls_fdata(lst, stat, flg);
	//maxsize;
		flg->maxlink < lst->n_link ? flg->maxlink = lst->n_link : 0;
		flg->maxsize < lst->f_size ? flg->maxsize = lst->f_size : 0;
		flg->maxblock < lst->b_size ? flg->maxblock = lst->b_size : 0;
		flg->totalblock += lst->b_size;
	}
	return (lst);
}

void				ls_fdata(t_list *lst, struct stat *stat, t_flags *flg)
{
	struct passwd	*passwd;
	struct group	*group;

	//f_rights data
	lst->f_rights = ft_memalloc(12);
	lst->f_rights[0] = (S_ISDIR(stat->st_mode) ? 'd' : '-');
	S_ISLNK(stat->st_mode) ? lst->f_rights[0] = 'l' : 0;
	S_ISCHR(stat->st_mode) ? lst->f_rights[0] = 'c' : 0;
	S_ISBLK(stat->st_mode) ? lst->f_rights[0] = 'b' : 0;
	lst->f_rights[1] = ((stat->st_mode & S_IRUSR) ? 'r' : '-');
	lst->f_rights[2] = ((stat->st_mode & S_IWUSR) ? 'w' : '-');
	lst->f_rights[3] = ((stat->st_mode & S_IXUSR) ? 'x' : '-');
	lst->f_rights[4] = ((stat->st_mode & S_IRGRP) ? 'r' : '-');
	lst->f_rights[5] = ((stat->st_mode & S_IWGRP) ? 'w' : '-');
	lst->f_rights[6] = ((stat->st_mode & S_IXGRP) ? 'x' : '-');
	lst->f_rights[7] = ((stat->st_mode & S_IROTH) ? 'r' : '-');
	lst->f_rights[8] = ((stat->st_mode & S_IWOTH) ? 'w' : '-');
	lst->f_rights[9] = ((stat->st_mode & S_IXOTH) ? 'x' : '-');
	(S_ISVTX & stat->st_mode) ? lst->f_rights[9] = 't' : '-';
	lst->f_rights[10] = (listxattr(flg->path_in, 0, 1024, XATTR_NOFOLLOW) ? '@' : ' ');

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

t_list		*ls_lstbubsort(t_list **lst_m, int mode)
{
	t_list	*lst;
	int		n;
	int		i;

	i = 1;
	n = 2;
	lst = *lst_m;
	while (lst != 0 && n++)
		lst = lst->next;
	lst = *lst_m;
	while (n-- && i < n && lst->next != 0 && (*lst_m)->next != 0)
	{
		while (i < n && lst->next != 0)
		{
			if (mode == 0 && ft_strcmp(lst->name, lst->next->name) < 0)
				ft_lstswap(lst_m , &lst);
			else if (mode == 1 && lst->time > lst->next->time)
				ft_lstswap(lst_m , &lst);
			lst = lst->next;
			i++;
		}
		lst = *lst_m;
		i = 1;
	}
	return (*lst_m);
}

void			ls_lstprint(t_list *lst,t_flags *flg, char *path)
{
	char	*buf;

	buf = ft_memalloc(255);
	(flg->l || flg->g) && flg->d != 1 && lst != 0 ? 
		printf("total %d\n", flg->totalblock) : 0;
	while (lst != 0)
	{
		if (flg->l == 1 || flg->g == 1)
		{
			flg->s == 1 ? printf("%*ld ", ((int)ft_intlen(flg->maxblock)),
					lst->b_size) : 0;
			printf("%-*s", ((int)ft_strlen(lst->f_rights)), lst->f_rights);
			printf("%*d ", (ft_intlen(flg->maxlink) + 1), lst->n_link);
			flg->g != 1 ? printf("%-*s ", ((int)ft_strlen(lst->u_name) + 1),
					lst->u_name) : 0;
			printf("%-*s ", ((int)ft_strlen(lst->gr_name) + 1), lst->gr_name);

			if (S_ISCHR(lst->st_mode) || S_ISBLK(lst->st_mode))
			{
				printf("%3d, ", lst->major);
				lst->minor > 255 ? printf("%3x ", lst->minor) :
					printf("%3d ", lst->minor);
			}
			else
				printf("%*lld ", (ft_intlen(flg->maxsize)), lst->f_size);
			ls_time(lst, flg);
		}
		printf("%s", lst->name);
		if (S_ISLNK(lst->st_mode) && (flg->l || flg->g))
		{
			if (flg->d == 1)
				readlink(path, buf, 255);
			else
				readlink(ls_pathmaker(path, lst->name), buf, 255);
			printf(" -> %s", buf);
		}
		printf("\n");
		if (flg->ext == 1)
			ls_xattributes(ls_pathmaker(path, lst->name));
		lst = lst->next;
	}
		//maxsizes to 0
		flg->maxlink = 0;
		flg->maxsize = 0;
		flg->maxblock = 0;
		flg->totalblock = 0;
}
