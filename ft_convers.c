/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/01/27 19:05:43 by vludan           ###   ########.fr       */
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
		if (S_ISDIR(temp->st_mode))
		{
			printf("\n:::::%s\n", temp->name);
//			path = ls_pathmaker(flg, temp->name); 
			recursive_dir_scan(temp->name, flg);
		}
		temp = temp->next;
	}
	free(head);
}

void				main_conv(t_flags *flg)
{
	if (flg->R == 1)
	{
		ls_pathmaker(flg, 0);
		recursive_dir_scan(*(*flg).path, flg);
	}
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
		if (stat(dien->d_name, buf) < 0)
			perror("Error: ");
		head = ls_lstnew(head, dien->d_name, buf, flg);
		free(buf);
	}
	closedir(dir);
	head = ls_lstsort(head,flg);
	ls_lstprint(head);
	return (head);
}

char			*ls_pathmaker(t_flags *flg, char *path)
{
	int			x;
	char		t[2];
	char		*temp;

	ft_strcpy(t, "/");
	x = 0;
	if (path == 0)
	{
		while (flg->path[x][0] != 0)
		{
			temp = ft_strjoin(flg->path[x], t);
			free(flg->path[x]);
			flg->path[x] = temp;
			x++;
		}
	}
	else
	{
		temp = ft_strjoin(temp, path);
		temp = ft_strjoin(temp, t);
	}
	return (temp);
}
