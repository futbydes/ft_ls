/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:57:45 by vludan            #+#    #+#             */
/*   Updated: 2018/01/30 14:01:32 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
