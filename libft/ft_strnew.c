/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:13 by vludan            #+#    #+#             */
/*   Updated: 2017/11/04 20:57:42 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		x;

	x = 0;
	s = (char*)malloc(sizeof(char) * size + 1);
	if (s == 0)
		return (0);
	while (size >= x)
		s[x++] = 0;
	return (s);
}
