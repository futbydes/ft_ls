/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:31:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 20:37:20 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst == 0 || f == 0)
		return (0);
	new = f(lst);
	head = new;
	if (new == 0)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (new->next == 0)
			return (head);
		new = new->next;
	}
	return (head);
}
