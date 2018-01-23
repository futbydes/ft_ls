/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:53:05 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 18:31:23 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_s(void const *content)
{
	int		x;

	x = 0;
	while (((unsigned char*)content)[x] != '\0')
		x++;
	return (x);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content_size = content_size;
	if (content == 0)
	{
		new->content_size = 0;
		new->content = 0;
	}
	else
	{
		new->content = malloc(len_s(content) + 1);
		ft_memcpy(new->content, content, len_s(content) + 1);
	}
	new->next = NULL;
	return (new);
}
