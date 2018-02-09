/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowcasealph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:02:24 by vludan            #+#    #+#             */
/*   Updated: 2017/12/21 11:43:37 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_lowcasealph(char **t)
{
	int		x;

	x = 0;
	while (**t != 0)
	{
		if (**t >= 'A' && **t <= 'Z')
			*(*t) += 32;
		(*t)++;
		x++;
	}
	(*t) -= x;
	return (*t);
}

char		*ft_charr(unsigned char t)
{
	char	*arr;

	arr = (char*)malloc(2);
	arr[0] = t;
	arr[1] = '\0';
	return (arr);
}
