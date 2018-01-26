/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/01/26 12:14:26 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				recursive_dir_scan(char *path, t_flags *flg)
{
	DIR				*dir;
	struct dirent	*dien;
	struct stat		*buf;
	t_list			*head;

	head = 0;
	if (!(dir = opendir(path)))
		return ;
	while ((dien = readdir(dir)) != 0)
	{
		if (dien->d_name[0] == '.' && (flg->a == 0 && flg->f == 0))
			continue ;
		buf = ft_memalloc(sizeof(buf));
		stat(dien->d_name, buf);
		head = ls_lstnew(head, dien->d_name, buf, flg);
	//printf(":::nextfile::::%s\n", head->name);
	}
	head = ls_lstsort(head, flg);
	ls_lstprint(head);
	while (head->next != 0)
	{
		printf("%hu\n", head->st_mode);
		if (head->st_mode == 16877)
		{
			printf("\n::::::%s\n\n", head->name);
			recursive_dir_scan(head->name, flg);
		}
		head = head->next;
	}
}

void	main_conv(t_flags *flg)
{
	if (flg->R == 1)
		recursive_dir_scan(".", flg);
/*	if (flg->path == 0)
		scan_dir(".", flags);
	if (flg->d == 1) //tol'ko pokazivat' put' fayla i ispol'zovat' ego dlya inf
		;
	if (flg->l == 1 || flg->g == 1)
		;
	if (flg->r == 1)
		; */
}

int			scan_dir(char *arg, t_flags *flg)
{
	DIR 	*dir;
	struct	dirent *dien;
	struct stat		*buf;
	t_list	*head;


	head = 0;
	if (!(dir = opendir(arg)))
		return (0);
	while ((dien = readdir(dir)) != 0)
	{
		if (dien->d_name[0] == '.' && (flg->a == 0 && flg->f == 0))
			continue ;
		if (flg->f == 1 && (flg->l == 0 || flg->a == 0)) //more condition?
			printf("%s\n", dien->d_name);
		else
		{
			buf = ft_memalloc(sizeof(buf));
			stat(dien->d_name, buf);
			head = ls_lstnew(head, dien->d_name, buf, flg);
		}
	}
	ls_lstsort(head,flg);
	return (1);
}

