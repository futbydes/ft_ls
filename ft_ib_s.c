/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ib_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:34:56 by vludan            #+#    #+#             */
/*   Updated: 2018/01/11 15:03:33 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t			num_len(intmax_t num, intmax_t base)
{
	intmax_t			x;

	x = 0;
	(num <= 0 && base == 10) ? x++ : 0;
	while (num)
	{
		num = num / base;
		x++;
	}
	return (x);
}

char					*ft_ib_s(intmax_t num, intmax_t base)
{
	char				*arr;
	char				*temp;
	intmax_t			x;

	x = num_len(num, base);
	x == 0 ? x++ : 0;
	arr = (char*)malloc(sizeof(char) * x + 1);
	temp = arr;
	num == 0 ? arr[0] = '0' : 0;
	(num < 0 && base == 10) ? arr[x - x] = '-' : 0;
	arr[x--] = 0;
	while (num < 0)
	{
		arr[x--] = (-1 * (num % base)) + (-1 * (num % base) > 9 ?
				'A' - 10 : '0');
		num = num / base;
	}
	if (num > 0)
		while (num)
		{
			arr[x--] = (num % base) + (num % base > 9 ? 'A' - 10 : '0');
			num = num / base;
		}
	return (temp);
}
