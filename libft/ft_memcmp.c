/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:47:17 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:19:48 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		x;
	int		y;
	int		z;

	x = n;
	z = 0;
	y = 0;
	while ((y != x) && (z == 0))
	{
		z = ((unsigned char*)s1)[y] - ((unsigned char*)s2)[y];
		y++;
	}
	return (z);
}
