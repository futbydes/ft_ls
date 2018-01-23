/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:41:16 by vludan            #+#    #+#             */
/*   Updated: 2017/11/02 16:54:16 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c;
	unsigned char	*b;
	int				x;

	x = 0;
	c = (unsigned char*)s1;
	b = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((c[x] == b[x]) && (--n > 0) && (c[x] != '\0') && (b[x] != '\0'))
		x++;
	return (c[x] - b[x]);
}
