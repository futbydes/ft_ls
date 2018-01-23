/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_sn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:51:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 21:05:42 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdel_sn(t_list *list)
{
	t_list	*head;

	if (list == 0)
		return (0);
	head = list->next;
	free(list);
	list = head;
	return (list);
}
