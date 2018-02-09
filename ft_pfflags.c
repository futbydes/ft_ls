/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:55:32 by vludan            #+#    #+#             */
/*   Updated: 2018/01/14 12:40:39 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_check(char **spec, t_flg *flags)
{
	if (**spec != 0 && (**spec == ' ' || **spec == '#' || **spec == '0' ||
				**spec == '-' || **spec == '+'))
	{
		while (**spec != 0 && (**spec == ' ' || **spec == '#' ||
					**spec == '0' || **spec == '-' || **spec == '+'))
		{
			**spec == ' ' ? flags->sps = 1 : 0;
			**spec == '-' ? flags->minus = 1 : 0;
			**spec == '+' ? flags->plus = 1 : 0;
			**spec == '+' ? flags->sign = 2 : 0;
			**spec == '#' ? flags->oct = 1 : 0;
			**spec == '0' ? flags->zero = 1 : 0;
			(*spec)++;
		}
		return (1);
	}
	else
		return (0);
}

int			min_width(char **spec, t_flg *flags, va_list pt)
{
	int		x;
	char	*arr;
	char	*temp;

	if ((**spec >= '0' && **spec <= '9') || **spec == '*')
	{
		if (**spec == '*')
			return (asterisk_neg(spec, flags, pt, 0));
		x = 0;
		while (**spec >= '0' && **spec <= '9' && (*spec)++)
			x++;
		temp = *spec;
		arr = ft_memalloc(x + 1);
		(*spec)--;
		while (**spec >= '0' && **spec <= '9' && x > 0)
			arr[x-- - 1] = *(*spec)--;
		flags->m_fw = ft_atoi(arr);
		free(arr);
		*spec = temp;
		return (1);
	}
	else
		return (0);
}

int			prescision(char **spec, t_flg *flags, va_list pt)
{
	int		x;
	char	*arr;
	char	*temp;

	if (**spec == '.' && (*spec)++)
	{
		if (**spec == '*')
			return (asterisk_neg(spec, flags, pt, 1));
		x = 0;
		if ((**spec < '0' || **spec > '9') && (flags->prc = 0))
			return (1);
		while (**spec >= '0' && **spec <= '9' && (*spec)++)
			x++;
		temp = *spec;
		arr = ft_memalloc(x + 1);
		(*spec)--;
		while (**spec >= '0' && **spec <= '9' && x-- > 0)
			arr[x] = *(*spec)--;
		flags->prc = ft_atoi(arr);
		free(arr);
		*spec = temp;
		return (1);
	}
	else
		return (0);
}
