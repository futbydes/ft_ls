/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:56:09 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:30:31 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *b)
{
	int		x;

	x = 0;
	while (b[x] != '\0')
		x++;
	return (x);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		x;

	x = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	s = (char*)malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (s == 0)
		return (0);
	while (*s1 != '\0')
		s[x++] = *s1++;
	while (*s2 != '\0')
		s[x++] = *s2++;
	s[x] = '\0';
	return (s);
}
