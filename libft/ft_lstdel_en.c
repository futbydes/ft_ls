/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_en.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:51:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 21:06:59 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdel_en(t_list *list)
{
	t_list	*head;

	if (list == 0)
		return (0);
	head = list;
	while (list->next->next != 0)
		list = list->next;
	free(list->next);
	list->next = 0;
	list = head;
	return (head);
}
