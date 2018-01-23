/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:57:45 by vludan            #+#    #+#             */
/*   Updated: 2017/11/04 16:26:49 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	count;

	count = 0;
	while ((count != len) && (src[count] != '\0'))
	{
		dst[count] = src[count];
		count++;
	}
	while (count != len)
		dst[count++] = '\0';
	return (dst);
}
