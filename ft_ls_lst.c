/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:29:58 by vludan            #+#    #+#             */
/*   Updated: 2018/01/27 19:05:47 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ls_lstsort(t_list *head, t_flags *flg)
{
	t_list		*sort;

	sort = 0;
	if (flg->f != 1)
		sort = ls_lstbubsort_alpha(&head);
	if (flg->r != 1)
		ls_lstrev(&sort);
	return (sort);
}

t_list			*ls_lstnew(t_list *head, char *name, struct stat *stat, t_flags *flg)
{
	t_list	*lst;

	lst = ft_memalloc(sizeof(t_list));
	lst->name = ft_memalloc((int)ft_strlen(name) + 1);
	name = ls_pathmaker(flg, name);
	ft_strcpy(lst->name, name);
	lst->st_mode = stat->st_mode;
	lst->next = head;
	if (flg->R == 1)
		;
	return (lst);
}
/*
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
		return (lst);
	}
	else
		return (0);
}
*/
t_list		*ls_lstbubsort_alpha(t_list **lst_m)
{
	t_list	*temp_c;
	t_list	*lst;
	int		n;
	int		i;

	i = 1;
	n = 1;
	temp_c = *lst_m;
	lst = *lst_m;
	while (temp_c != 0)
	{
		n++;
		temp_c = temp_c->next;
	}
	while (i < n && lst->next != 0 && (*lst_m)->next != 0)
	{
		while (i < n && lst->next != 0)
		{
			if (ft_strcmp(lst->name, lst->next->name) < 0)
				ft_lstswap(lst_m , &lst);
			lst = lst->next;
			i++;
		}
		lst = *lst_m;
		n--;
		i = 1;
	}
	return (*lst_m);
}

void			ls_lstprint(t_list *head)
{
	while (head != 0)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}

