/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:35:26 by vludan            #+#    #+#             */
/*   Updated: 2017/12/20 15:57:23 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cp;

	dst_cp = (unsigned char*)dst;
	if ((dst <= src) || (dst >= src + len))
	{
		while (len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char*)dst-- = *(unsigned char*)src--;
	}
	return (dst_cp);
}
