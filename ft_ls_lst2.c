/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:19:12 by vludan            #+#    #+#             */
/*   Updated: 2018/01/23 17:08:16 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_lstswap(t_list **lst, t_list *swp, t_list **head)
{
	t_list		*temp;
	t_list		*temp2;

	if (lst == head)
	{
		(*lst)->next = (*lst)->next->next;
		swp->next = (*lst);
		(*lst) = swp;
		head = lst;
	}
	else
	{
		temp = *head;
		temp2 = (*lst)->next->next;
		while (temp->next != (*lst))
			temp = temp->next;
		temp->next = swp;
		swp->next = *lst;
		(*lst)->next = temp2;
	}
}

