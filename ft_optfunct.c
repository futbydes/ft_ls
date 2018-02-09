/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:38:16 by vludan            #+#    #+#             */
/*   Updated: 2018/01/14 12:40:07 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_realloc(char **arr, int size, t_or *u)
{
	char	*new;
	int		len;

	if (!arr)
		return (*arr);
	len = ft_strlen(*arr);
	new = ft_memalloc((len + size) + 1);
	new = ft_memcpy(new, *arr, len + size);
	if (&(u->arr) != arr)
		free(*arr);
	return (new);
}

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

void		dollar_con(char **spec, va_list pt)
{
	int		s;
	int		i;

	s = 0;
	s = **spec - 49;
	while (s > 0)
	{
		i = va_arg(pt, int);
		s--;
	}
	(*spec) += 2;
	return ;
}

int			asterisk_neg(char **spec, t_flg *flags, va_list pt, int flg)
{
	if (flg == 1 && (*spec)++)
	{
		flags->prc = va_arg(pt, int);
		return (1);
	}
	else
	{
		(*spec)++;
		flags->m_fw = va_arg(pt, int);
		if (flags->m_fw < 0)
		{
			flags->m_fw *= -1;
			flags->minus = 1;
			return (1);
		}
	}
	return (1);
}
