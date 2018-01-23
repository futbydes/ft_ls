/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:51:33 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 21:09:07 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstprint(t_list *list)
{
	if (list == 0)
		return (0);
	ft_putstr(":START:\n");
	while (list->next != NULL)
	{
		ft_putstr(list->content);
		ft_putchar('\n');
		list = list->next;
	}
	ft_putstr(list->content);
	ft_putstr(":END:");
	return (0);
}
