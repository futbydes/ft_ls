/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/02/11 14:26:20 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				recursive_dir_scan(char *path, t_flags *flg)
{
	t_list			*head;
	t_list			*temp;

	head = scan_dir(path, flg);
	temp = head;
	while (temp != 0)
	{
		if (S_ISDIR(temp->st_mode) && ft_strcmp(temp->name, ".") &&
				ft_strcmp(temp->name, ".."))
		{
			flg->path_in = ls_pathmaker(path, temp->name);
			ft_printf("\n%s:\n", flg->path_in);
			recursive_dir_scan(flg->path_in, flg);
		}
		temp = temp->next;
	}
	free(path);
	head != 0 ? ls_lstfree(head, flg, 1) : 0;
}

void				main_conv(t_flags *flg)
{
	struct stat		*buf;
	t_list			*temp;
	int				x;

	x = 0;
	buf = 0;
	while (flg->path[x][0] != 0)
	{
		temp = 0;
		if (flg->d == 1)
			ls_d_conv(flg->path[x], flg);
		else if (flg->f_r == 1 && flg->d != 1)
			recursive_dir_scan(flg->path[x], flg);
		else
			x = scan_path(x, flg, buf);
		if (flg->d == 1)
			break ;
		x++;
	}
	ls_lstfree(0, flg, 2);
}

int					scan_path(int x, t_flags *flg, struct stat *buf)
{
	t_list			*head;
	t_list			*f_head;

	f_head = 0;
	head = 0;
	while (flg->path[x][0] != 0)
	{
		buf = ft_memalloc(sizeof(struct stat));
		while (lstat(flg->path[x], buf) < 0)
		{
			ls_error_msg(strerror(errno), flg->path[x]);
			free(buf);
			scan_path_op(x, flg, f_head, head);
			return (x);
		}
		flg->path_in = flg->path[x];
		if (S_ISDIR(buf->st_mode))
			head = ls_lstnew(head, flg->path[x], buf, flg);
		else
			f_head = ls_lstnew(f_head, flg->path[x], buf, flg);
		free(buf);
		x++;
	}
	scan_path_op(x, flg, f_head, head);
	return (x - 1);
}

void				scan_path_op(int x, t_flags *flg, t_list *f_head,
		t_list *head)
{
	t_list			*temp;
	t_list			*temp2;

	if (!f_head && !head)
		return ;
	f_head != 0 ? f_head = ls_lstsort(f_head, flg) : 0;
	f_head != 0 ? f_head = ls_lstprint(f_head, flg, flg->path[x]) : 0;
	f_head != 0 ? ls_lstfree(f_head, flg, 1) : 0;
	head != 0 ? head = ls_lstsort(head, flg) : 0;
	temp = head;
	while (head != 0)
	{
		x > 1 ? ft_printf("%s:\n", head->name) : 0;
		temp2 = scan_dir(head->name, flg);
		head = head->next;
		ls_lstfree(temp2, flg, 1);
		head != 0 ? ft_printf("\n") : 0;
	}
	temp != 0 ? ls_lstfree(head, flg, 1) : 0;
}

t_list				*scan_dir(char *arg, t_flags *flg)
{
	DIR				*dir;
	struct dirent	*dien;
	struct stat		*buf;
	t_list			*head;

	head = 0;
	if (!(dir = opendir(arg)))
		return (ls_error_msg(strerror(errno), arg));
	while ((dien = readdir(dir)) != 0)
	{
		if (dien->d_name[0] == '.' && (flg->a == 0 && flg->f == 0))
			continue ;
		buf = ft_memalloc(sizeof(struct stat));
		flg->path_in = ls_pathmaker(arg, dien->d_name);
		if (lstat(flg->path_in, buf) < 0)
			perror("");
		head = ls_lstnew(head, dien->d_name, buf, flg);
		flg->path_in != 0 ? free(flg->path_in) : 0;
		free(buf);
	}
	closedir(dir);
	head = ls_lstsort(head, flg);
	head = ls_lstprint(head, flg, arg);
	return (head);
}
