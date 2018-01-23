/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:25:56 by vludan            #+#    #+#             */
/*   Updated: 2017/11/09 10:56:46 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(char const *s, char c)
{
	int			count;
	int			x;

	x = 0;
	count = 0;
	if (s[x] == '\0')
		return (count);
	while ((s[x] == c) && (s[x] != '\0'))
		x++;
	while ((s[x] != c) && (s[x] != '\0'))
	{
		count++;
		x++;
	}
	return (count);
}

static int		main_len(char const *s, char c)
{
	int			x;
	int			count;

	x = 0;
	count = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
		{
			count++;
			while (s[x] == c)
				x++;
		}
		x++;
	}
	if (count == 0)
		count++;
	return (count);
}

static char		**stringalloc(const char **s, int z, char c, char **arr)
{
	int			y;

	y = 0;
	arr[z] = (char*)malloc(sizeof(char*) * len(*s, c) + 1);
	while (arr[z] == 0 && z >= 0)
	{
		free(arr[z]);
		z--;
		if (z < 0)
		{
			free(arr);
			return (0);
		}
	}
	if (*s != '\0')
		while ((**s != c) && (**s != '\0'))
			arr[z][y++] = *(*s)++;
	arr[z][y] = '\0';
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int			z;
	char		**arr;

	if ((s == 0) || (c == 0))
		return (0);
	z = 0;
	arr = (char**)malloc(sizeof(char*) * (main_len(s, c) + 1) * 8);
	if (arr == 0)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			stringalloc(&s, z, c, arr);
			z++;
		}
	}
	arr[z] = 0;
	return (arr);
}
