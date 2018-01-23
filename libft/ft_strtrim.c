/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:16:03 by vludan            #+#    #+#             */
/*   Updated: 2017/11/04 21:08:36 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_white(const char *s)
{
	int		x;
	int		w;

	x = 0;
	while (s[x] != '\0')
		x++;
	x--;
	while ((s[x] == ' ') || (s[x] == '\n') || (s[x] == '\t'))
	{
		x--;
		if (x == 0)
			return (0);
	}
	w = x;
	x = 0;
	while ((s[x] == ' ') || (s[x] == '\n') || (s[x] == '\t'))
		x++;
	w -= x;
	return (w + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*m;
	int		x;
	int		y;

	if (s == 0)
		return (0);
	y = 0;
	x = 0;
	m = (char*)malloc(sizeof(char) * len_white(s) + 1);
	if (m == 0)
		return (0);
	if (s[x] == '\0')
	{
		m[x] = '\0';
		return (m);
	}
	while ((s[x] == ' ') || (s[x] == '\n') || (s[x] == '\t'))
		x++;
	while ((len_white(s) > y) && (s[x] != '\0'))
		m[y++] = s[x++];
	m[y] = '\0';
	return (m);
}
