/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:15:22 by vludan            #+#    #+#             */
/*   Updated: 2017/11/04 18:24:38 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	x;
	unsigned int	z;

	if (s == 0)
		return (0);
	x = 0;
	z = 0;
	a = malloc(sizeof(char) * (len) + 1);
	if (a == 0)
		return (0);
	while ((s[start] != '\0') && (len != 0))
	{
		a[z++] = s[start++];
		len--;
	}
	a[z] = '\0';
	return (a);
}
