/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ib_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:34:56 by vludan            #+#    #+#             */
/*   Updated: 2018/01/11 15:03:11 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static uintmax_t			num_len(uintmax_t num, uintmax_t base)
{
	uintmax_t				x;

	x = 0;
	(num <= 0 && base == 10) ? x++ : 0;
	while (num)
	{
		num = num / base;
		x++;
	}
	return (x);
}

char						*ft_ib_u(uintmax_t num, uintmax_t base)
{
	char					*arr;
	char					*temp;
	uintmax_t				x;

	x = num_len(num, base);
	x == 0 ? x++ : 0;
	arr = (char*)malloc(sizeof(char) * x + 1);
	temp = arr;
	arr[x--] = 0;
	num == 0 ? arr[0] = '0' : 0;
	if (num > 0)
		while (num)
		{
			arr[x--] = (num % base) + (num % base > 9 ? 'A' - 10 : '0');
			num = num / base;
		}
	return (temp);
}
