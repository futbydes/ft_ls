/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:21:39 by vludan            #+#    #+#             */
/*   Updated: 2018/01/13 10:58:17 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*digit_conv(t_flg *flags, t_or *u)
{
	char	*t;

	flags->type == 0 ? t = ft_memalloc(0) : 0;
	if (flags->type == 'd' || flags->type == 'D' || 'i' == flags->type)
		t = ft_ib_s(u->s, 10);
	if (flags->type == 'o' || flags->type == 'O')
		t = ft_ib_u(u->us, 8);
	if (flags->type == 'u' || flags->type == 'U')
		t = ft_ib_u(u->us, 10);
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
		t = ft_ib_u(u->us, 16);
	if ((flags->type == 'c' && flags->size == 3) || flags->type == 'C')
		t = ft_unicon(flags, u);
	if (flags->type == '%' || (flags->type == 'c' && flags->size != 3))
		t = (flags->type == '%' ? ft_charr('%') : ft_charr(u->uc));
	if ((flags->type == 's' || flags->type == 'S') && u->arr == 0 &&
			flags->awct == 0)
		t = ft_null_arr(flags, t);
	else if (flags->type == 's' && 3 != flags->size)
		t = ft_realloc(&(u->arr), 0, u);
	else if ((flags->type == 's' && 3 == flags->size) || flags->type == 'S')
		t = ft_unicon(flags, u);
	return (t);
}

char		*presc_conv(t_flg *lst, char *t, t_or *u)
{
	int		x;
	char	*temp;

	*t == '-' ? lst->sign = 1 : 0;
	x = lst->prc - (((lst->type == 'o' || lst->type == 'O') && lst->prc != 0
				&& u->s == 0) ? 0 : (int)ft_strlen(t));
	if ((lst->type == 'o' || lst->type == 'O') && (1 == lst->oct && x-- &&
				lst->prc == 0))
		return (t);
	else if (0 == lst->prc && u->s == 0 && lst->type != '%')
		return (t = ft_memalloc(0));
	else if (x >= 0 && 's' != lst->type && 'S' != lst->type &&
			lst->type != 'c' && lst->type != 'C' && lst->type != '%')
	{
		t = ft_realloc(&t, x, u);
		temp = t;
		ft_memmove(t + x, t, (((lst->type == 'o' || lst->type == 'O') &&
						u->s == 0 && 1 != lst->oct) ? 0 : ft_strlen(t)));
		temp = ft_memset(temp, '0', (lst->sign == 1 ? x + 1 : x));
		return (temp);
	}
	else if (('s' == lst->type || 'S' == lst->type) && x < 0)
		t = ft_realloc(&t, x, u);
	lst->type == '%' ? lst->prc = -1 : 0;
	return (t);
}

char		*ft_format_str(t_flg *lst, char *t, t_or *u)
{
	*t == '-' ? (lst->sign = 1) : 0;
	lst->zero == 1 ? t = ft_format_zero(lst, t, u) : 0;
	lst->sps == 1 ? t = ft_addspace(lst, t, u) : 0;
	if (lst->sign > 0 || lst->oct == 1 || lst->type == 'p' ||
			lst->plus == 1)
		t = ft_addsign(lst, t, u);
	if (lst->minus == 1 || lst->m_fw > (int)ft_strlen(t))
		t = alignment_mfw(lst, t, u);
	if (lst->type == 'p' || (lst->type == 'x'))
		t = ft_lowcasealph(&t);
	if ((lst->type == 'C' || lst->type == 'c') && *t == 0 && lst->minus == 1)
		lst->btread = ft_strlen(t + 1);
	else if ((lst->type == 'C' || lst->type == 'c') && u->uc == 0)
		lst->btread = ft_strlen(t) + 1;
	return (t);
}

char		*ft_null_arr(t_flg *lst, char *t)
{
	t = ft_memalloc((lst->prc == -1 ? 1 : 7));
	ft_strcpy(t, "(null)");
	return (t);
}
