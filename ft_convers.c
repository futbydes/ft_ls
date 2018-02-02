/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/02/02 11:05:45 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				recursive_dir_scan(char *path, t_flags *flg)
{
	t_list			*head;
	t_list			*temp;

	head = scan_dir(path,flg);
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
	free(head);
}

void				main_conv(t_flags *flg)
{
	struct stat 	*buf;

	buf = ft_memalloc(sizeof(struct stat));
	lstat(*(*flg).path, buf);
	if (flg->d == 1 || S_ISLNK(buf->st_mode))
		ls_d_conv(*(*flg).path, flg);
	else if (flg->R == 1 && flg->d != 1)
		recursive_dir_scan(*(*flg).path, flg);
	else
		scan_dir(*(*flg).path, flg);
/*	if (flg->path == 0)
		scan_dir(".", flags);
	if (flg->d == 1) //tol'ko pokazivat' put' fayla i ispol'zovat' ego dlya inf
		;
	if (flg->l == 1 || flg->g == 1)
		;
	if (flg->r == 1)
		; */
}

t_list				*scan_dir(char *arg, t_flags *flg)
{
	DIR 			*dir;
	struct dirent	*dien;
	struct stat		*buf;
	t_list			*head;

	head = 0;
	if (!(dir = opendir(arg)))
		return (0);
	while ((dien = readdir(dir)) != 0)
	{
		if (dien->d_name[0] == '.' && (flg->a == 0 && flg->f == 0))
			continue ;
		buf = ft_memalloc(sizeof(struct stat));
		flg->path_in = ls_pathmaker(arg,dien->d_name);
		if (lstat((ft_strcmp(arg, ".") ? flg->path_in = ls_pathmaker(arg,
							dien->d_name) : dien->d_name), buf) < 0)
			perror("Error: ");
		head = ls_lstnew(head, dien->d_name, buf, flg);
		free(buf);
	}
	closedir(dir);
	head = ls_lstsort(head,flg);
	ls_lstprint(head, flg, arg);
	return (head);
}

char			*ls_pathmaker(char *path, char *new_fld)
{
	char		t[2];
	char		*temp;

	ft_strcpy(t, "/");
	temp = ft_strjoin(path, t);
	temp = ft_strjoin(temp, new_fld);
	return (temp);
}
