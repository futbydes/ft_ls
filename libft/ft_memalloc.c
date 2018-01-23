/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:24:20 by vludan            #+#    #+#             */
/*   Updated: 2017/11/02 15:40:35 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;
	void	*h;

	area = malloc(size);
	if (area == 0)
		return (0);
	h = area;
	while (size != 0)
	{
		*(unsigned char*)area++ = 0;
		size--;
	}
	return (h);
}
