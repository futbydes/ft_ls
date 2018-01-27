/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:19:12 by vludan            #+#    #+#             */
/*   Updated: 2018/01/27 19:05:50 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstswap(t_list **head, t_list **swp)
{
	t_list	*next;
	t_list	*prev;
	t_list	*root;

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

void		ls_lstrev(t_list **head)
{
	t_list	*next;
	t_list	*root;

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
