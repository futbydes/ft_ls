/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:51:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 21:08:42 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lstadd_end(t_list *node, t_list **list)
{
	t_list		*head;

	head = *list;
	if (node == 0 || list == 0)
		return (0);
	while ((*list)->next != NULL)
		(*list) = (*list)->next;
	(*list)->next = node;
	node->next = 0;
	(*list) = head;
	return (list);
}
