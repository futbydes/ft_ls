/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:32:00 by vludan            #+#    #+#             */
/*   Updated: 2018/01/13 11:01:44 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		size_check_hl(char **spec, t_flg *flags)
{
	int		y;

	while (**spec != 0 && (**spec == 'h' || **spec == 'l'))
	{
		y = 1;
		if (**spec == 'h')
		{
			while (**spec == 'h' && y++)
				(*spec)++;
			((y - 1) % 2 == 0 && hh > flags->size) ? flags->size = hh : 0;
			((y - 1) % 2 != 0 && h > flags->size) ? flags->size = h : 0;
		}
		y = 1;
		if (**spec == 'l')
		{
			while (**spec == 'l' && y++)
				(*spec)++;
			((y - 1) % 2 == 0 && ll > flags->size) ? flags->size = ll : 0;
			((y - 1) % 2 != 0 && l > flags->size) ? flags->size = l : 0;
		}
	}
}

void		size_check_jz(char **spec, t_flg *flags)
{
	while (**spec != 0 && (**spec == 'j' || **spec == 'z'))
	{
		if (**spec == 'z')
		{
			flags->size < z ? flags->size = z : 0;
			(*spec)++;
		}
		if (**spec == 'j')
		{
			flags->size < j ? flags->size = j : 0;
			(*spec)++;
		}
	}
}

int			size_check(char **spec, t_flg *flags)
{
	if (**spec == 'h' || **spec == 'l' || **spec == 'j' || **spec == 'z')
	{
		while ((**spec == 'h' || **spec == 'l' || **spec == 'j' ||
					**spec == 'z') && (**spec != 0))
		{
			(**spec == 'h' || **spec == 'l') ? size_check_hl(spec, flags) : 0;
			(**spec == 'j' || **spec == 'z') ? size_check_jz(spec, flags) : 0;
		}
		return (1);
	}
	else
		return (0);
}
