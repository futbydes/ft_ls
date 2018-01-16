/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:24:20 by vludan            #+#    #+#             */
/*   Updated: 2018/01/16 15:27:07 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
