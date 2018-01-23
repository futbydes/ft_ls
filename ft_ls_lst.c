/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:29:58 by vludan            #+#    #+#             */
/*   Updated: 2018/01/23 16:52:56 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ls_lstsort(t_list *head, t_flags *flg)
{
	t_list		*sort;

	sort = 0;
	if (flg->f != 1)
	{
		sort = ls_lstalphsort(head);
	}
	return (sort);
	/*
	if (flg->l)
	if (flg->t || flg->u)
		;
	if (flg->r)
		; */
}

t_list			*ls_lstnew(t_list *head, char *name, struct stat *stat, t_flags *flg)
{
	t_list	*lst;

	lst = ft_memalloc(sizeof(t_list));
	lst->name = ft_memalloc((int)ft_strlen(name) + 1);
	ft_strcpy(lst->name, name);
	lst->st_mode = stat->st_mode;
	lst->next = head;
	if (flg->R == 1)
		;
/*	lst->
	if (stat != 0)
		; */
	return (lst);
}

t_list		*ls_lstpushup(t_list *lst, t_list *temp)
{
	t_list	*head;

	if (lst != 0 && temp != 0)
	{
		head = temp;
		while (temp->next != lst && temp->next != 0)
			temp = temp->next;
		temp->next = temp->next->next;
		lst->next = head;
		ls_lstprint(lst);
		printf("\n");
		return (lst);
	}
	else
		return (0);
}

t_list		*ls_lstalphsort(t_list *lst)
{
	t_list	*temp;
	t_list	*head;

	temp = lst;
	while (lst != 0)
	{
		if (ft_strcmp(temp->name, lst->name) > 0)
			temp = ls_lstpushup(lst, temp);
		lst = lst->next;
	}
	head = temp;
	while ((temp = temp->next) != 0)
	{
		lst = temp;
		while (lst != 0)
		{
			if (ft_strcmp(temp->name, lst->name) > 0)
				temp = ls_lstpushup(lst, temp);
			lst = lst->next;
		}
	}
//	ls_lstprint(temp);
	return (head);
}

void		ls_lstbubsort(t_list **lst_m)
{
	t_list	*temp_c;
	t_list	*lst;
	int		n;
	int		i;

	i = 1;
	n = 1;
	temp_c = *lst_m;
	lst = *lst_m;
	while ((temp_c = temp_c->next) != 0)
		n++;
	while (i < n)
	{
		while (i < n && lst->next != 0)
		{
			lst = lst->next;
			if (ft_strcmp(lst->name, lst->next->name) < 0)
				ls_lstswap(&lst, lst->next, lst_m);
			i++;
		}
		lst = *lst_m;
		n--;
		i = 1;
	}
	ls_lstprint(*lst_m);
}



void		ls_lstprint(t_list *head)
{
	while (head != 0)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}
