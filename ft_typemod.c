/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typemod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:38:23 by vludan            #+#    #+#             */
/*   Updated: 2018/01/13 11:01:58 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					type_check(char **spec, t_flg *flags)
{
	int				x;
	char			type_mod[16];

	x = 0;
	ft_strcpy(type_mod, "sSpdDioOuUxXcC%");
	while (type_mod[x] != 0 && **spec != 0)
	{
		if (**spec == type_mod[x])
		{
			flags->type = type_mod[x];
			(*spec)++;
			return (1);
		}
		x++;
	}
	return (0);
}

void				type_conv_u(t_flg *flags, va_list pt, t_or *u)
{
	if ((flags->size == 6 || flags->type == 'p')
			&& flags->type != 'U' && flags->type != 'O')
		u->us = va_arg(pt, size_t);
	else if (flags->size == 0 && flags->type != 'U' && flags->type != 'O')
		u->us = va_arg(pt, unsigned int);
	else if (flags->size == 1 && flags->type != 'U' && flags->type != 'O')
		u->us = (unsigned char)va_arg(pt, int);
	else if (flags->size == 2 && flags->type != 'U' && flags->type != 'O')
		u->us = (unsigned short int)va_arg(pt, int);
	else if (flags->size == 3 || (flags->type == 'U' || flags->type == 'O'))
		u->us = va_arg(pt, unsigned long int);
	else if (flags->size == 4 && flags->type != 'U' && flags->type != 'O')
		u->us = va_arg(pt, unsigned long long int);
	else if (flags->size == 5 && flags->type != 'U' && flags->type != 'O')
		u->us = va_arg(pt, uintmax_t);
}

void				type_conv_s(t_flg *flags, va_list pt, t_or *u)
{
	if (flags->size == 0 && !type_conv_sflgs(flags))
		u->s = va_arg(pt, int);
	else if (flags->size == 1 && !type_conv_sflgs(flags))
		u->s = (char)va_arg(pt, int);
	else if (flags->size == 2 && !type_conv_sflgs(flags))
		u->s = (short int)va_arg(pt, int);
	else if (flags->type == 'S' || (flags->type == 's' && flags->size == 3))
		flags->awct = va_arg(pt, wchar_t*);
	else if ((flags->type == 'c' && flags->size == 3) || 'C' == flags->type)
		u->wct = va_arg(pt, wchar_t);
	else if (flags->size == 3 || 'D' == flags->type)
		u->s = va_arg(pt, long int);
	else if (flags->size == 4 && !type_conv_sflgs(flags))
		u->s = va_arg(pt, long long int);
	else if ((flags->size == 5 || flags->size == 6) && !type_conv_sflgs(flags))
		u->s = va_arg(pt, intmax_t);
	else if (flags->type == 's' && flags->size != 3)
		u->arr = va_arg(pt, char*);
	else if (flags->type == 'c' && flags->size != 3)
		u->c = va_arg(pt, int);
}

int					type_conv_uors(t_flg *f)
{
	if (f->type == 'u' || f->type == 'U' || f->type == 'x' || f->type == 'X' ||
			f->type == 'o' || f->type == 'O' || f->type == 'p')
		return (1);
	else
		return (0);
}

int					type_conv_sflgs(t_flg *f)
{
	if ('s' == f->type || 'S' == f->type || 'D' == f->type || 'c' == f->type ||
			'C' == f->type)
		return (1);
	else
		return (0);
}
