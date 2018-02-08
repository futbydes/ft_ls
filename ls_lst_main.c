/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:19:12 by vludan            #+#    #+#             */
/*   Updated: 2018/02/08 12:55:12 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_lstswap(t_list **head, t_list **swp)
{
	t_list		*next;
	t_list		*prev;
	t_list		*root;

	prev = 0;
	root = *head;
	while ((*head) != (*swp))
	{
		prev = (*head);
		(*head) = (*head)->next;
	}
	if ((*head) == (*swp))
	{
		next = (*swp)->next;
		(*swp)->next = (*swp)->next->next;
		next->next = (*swp);
		if (prev != 0)
		{
			prev->next = next;
			(*head) = root;
		}
		else
			(*head) = next;
		(*swp) = next;
	}
}

void			ls_lstrev(t_list **head)
{
	t_list		*next;
	t_list		*root;

	root = 0;
	while ((*head))
	{
		next = (*head)->next;
		(*head)->next = root;
		root = (*head);
		(*head) = next;
	}
	(*head) = root;
}

t_list			*ls_lstbubsort(t_list **lst_m, int mode)
{
	t_list		*lst;
	int			n;
	int			i;

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
				ft_lstswap(lst_m, &lst);
			else if (mode == 1 && lst->time > lst->next->time)
				ft_lstswap(lst_m, &lst);
			lst = lst->next;
			i++;
		}
		lst = *lst_m;
		i = 1;
	}
	return (*lst_m);
}

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

void			ls_lstfree(t_list *head)
{
	t_list		*temp;

	while (head != 0)
	{
		temp = head;
		head->name != 0 ? free(head->name) : 0;
		head->u_name != 0 ? free(head->u_name) : 0;
		head->gr_name != 0 ? free(head->gr_name) : 0;
		head->f_rights != 0 ? free(head->f_rights) : 0;
		head->xattr != 0 ? free(head->xattr) : 0;
		head = head->next;
		free(temp);
	}
}
