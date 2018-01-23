/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:51:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 21:08:26 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdel_id(t_list *list, int id)
{
	int		d;
	t_list	*temp;
	t_list	*head;

	d = 0;
	if (list == 0 || id < 0)
		return (0);
	if (id == 0)
		return (ft_lstdel_sn(list));
	head = list;
	while (d < (id - 1) && list->next != 0)
	{
		list = list->next;
		d++;
	}
	if (d == (id - 1))
	{
		temp = list->next;
		list->next = temp->next;
		free(temp);
	}
	return (head);
}
