/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:19:44 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 15:10:34 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_lenght(int num)
{
	int		x;

	x = 0;
	if (num < 0)
		x++;
	while ((num = num / 10) != 0)
		x++;
	return (x);
}

static char	*er_zero(char *b)
{
	b = (char*)malloc(sizeof(char) * 2);
	b[0] = '0';
	b[1] = '\0';
	return (b);
}

char		*ft_itoa(int n)
{
	char	*b;
	int		z;

	b = NULL;
	if (n == 0)
		return (er_zero(b));
	z = arr_lenght(n);
	b = (char*)malloc(sizeof(char) * z + 2);
	if (b == 0)
		return (0);
	b[(z + 1)] = '\0';
	if (n < 0)
		b[0] = '-';
	while (n != 0)
	{
		if (n < 0)
			b[z--] = -1 * (n % 10) + '0';
		else
			b[z--] = n % 10 + '0';
		n /= 10;
	}
	return (b);
}
