/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:44:02 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:52:51 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*m;
	unsigned int	x;

	x = 0;
	if (s == 0 || f == 0)
		return (0);
	m = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (m == 0)
		return (0);
	while (s[x] != '\0')
	{
		m[x] = f(x, s[x]);
		x++;
	}
	m[x] = '\0';
	return (m);
}
