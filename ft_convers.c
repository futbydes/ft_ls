/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/01/30 18:45:51 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				recursive_dir_scan(char *path, t_flags *flg)
{
	t_list			*head;
	t_list			*temp;
	char			*cur_path;

	head = scan_dir(path,flg);
	temp = head;
	while (temp != 0)
	{
		if (S_ISDIR(temp->st_mode))
		{
			cur_path = ls_pathmaker(path, temp->name);
			printf("\n%s:\n", cur_path);
			recursive_dir_scan(cur_path, flg);
		}
		temp = temp->next;
	}
	free(head);
}

void				main_conv(t_flags *flg)
{
	if (flg->d == 1)
		;//pokazivat' katalog kak obicniy fayl no s sohraneniem infy ot "l" k primeru
	if (flg->R == 1)
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
		if (lstat((ft_strcmp(arg, ".") ? ls_pathmaker(arg, dien->d_name)
						: dien->d_name), buf) < 0)
			perror("Error: ");
		head = ls_lstnew(head, dien->d_name, buf, flg, arg);
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
