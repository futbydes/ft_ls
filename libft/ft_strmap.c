/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:44:02 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:52:28 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int		x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*m;
	int		x;

	x = 0;
	if (s == 0 || f == 0)
		return (0);
	m = (char*)malloc(sizeof(char) * len(s) + 1);
	if (m == 0)
		return (0);
	while (s[x] != '\0')
	{
		m[x] = f(s[x]);
		x++;
	}
	m[x] = '\0';
	return (m);
}
