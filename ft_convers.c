/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/02/09 10:19:53 by vludan           ###   ########.fr       */
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
			printf("\n%s:\n", flg->path_in);
			recursive_dir_scan(flg->path_in, flg);
		}
		temp = temp->next;
	}
	free(path);
	head != 0 ? ls_lstfree(head) : 0;
}

void				main_conv(t_flags *flg)
{
	struct stat		*buf;
	t_list			*temp;
	int				x;

	x = -1;
	while (x++ > -2 && flg->path[x][0] != 0)
	{
		temp = 0;
		flg->path[1][0] != 0 ? printf("%s:\n", flg->path[x]) : 0;
		buf = ft_memalloc(sizeof(struct stat));
		lstat(flg->path[x], buf);
		if (flg->d == 1 || S_ISLNK(buf->st_mode))
			ls_d_conv(flg->path[x], flg);
		else if (flg->f_r == 1 && flg->d != 1)
			recursive_dir_scan(flg->path[x], flg);
		else
			temp = scan_dir(flg->path[x], flg);
		free(buf);
		temp != 0 && flg->f_r != 1 ? ls_lstfree(temp) : 0;
		flg->path[x + 1][0] != 0 ? printf("\n") : 0;
	}
	x = -1;
	while (++x && flg->path[x][0])
		free(flg->path[x]);
	free(flg->path);
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
