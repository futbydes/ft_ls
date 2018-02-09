/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:28:14 by vludan            #+#    #+#             */
/*   Updated: 2018/01/13 10:58:36 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_addspace(t_flg *lst, char *t, t_or *u)
{
	char	*new;

	if (lst->sign == 0 && lst->plus == 0 && (lst->type == 'd' ||
				lst->type == 'D' || lst->type == 'i'))
	{
		new = ft_realloc(&t, 1, u);
		ft_memmove(new + 1, new, ft_strlen(new));
		new[0] = ' ';
		return (new);
	}
	else
		return (t);
}

char		*ft_format_zero(t_flg *lst, char *t, t_or *u)
{
	char	*new;
	char	*temp;
	int		x;

	x = lst->m_fw - ((lst->type == 'C' || lst->type == 'c') ? 1 : ft_strlen(t));
	(lst->sps == 1 && lst->sign == 0) ? x-- : 0;
	lst->type == 'p' ? x -= 2 : 0;
	if (x > 0 && lst->oct == 1 && ft_addsign_condition(lst, t, u))
		(lst->type == 'x' || lst->type == 'X') ? (x -= 2) : (x -= 1);
	if (x > -1 && lst->m_fw > 0 && lst->minus == 0 && lst->prc < lst->m_fw &&
			(lst->prc < 0 || lst->type == 's' || lst->type == 'S' ||
			lst->type == 'C' || lst->type == 'c' || lst->type == 0))
	{
		new = ft_realloc(&t, (lst->sign > 0 ? (x - 1) : x), u);
		temp = new;
		ft_memmove(new + (lst->sign > 0 ? (x - 1) : x), new, ft_strlen(new));
		temp = ft_memset(temp, '0', (lst->sign == 2 ? (x - 1) : x));
		lst->m_fw = 0;
		lst->zero = 0;
	}
	else
		return (t);
	return (temp);
}

char		*ft_addsign(t_flg *lst, char *t, t_or *u)
{
	char	*temp;
	char	*temp2;
	char	*new;

	if (ft_addsign_condition(lst, t, u))
	{
		temp = ft_memalloc(3);
		temp[0] = '0';
		if (lst->type == 'x' || lst->type == 'X' || lst->type == 'p')
			temp[1] = 'X';
		lst->sign == 1 ? temp[0] = '-' : 0;
		if (lst->plus == 1 && lst->sign == 2 &&
				(lst->type == 'd' || lst->type == 'i' || lst->type == 'D'))
			temp[0] = '+';
		new = ft_realloc(&t, ft_strlen(temp), u);
		temp2 = new;
		ft_memmove(new + ft_strlen(temp), new, ft_strlen(new));
		ft_memcpy(temp2, temp, ft_strlen(temp));
		free(temp);
		return (temp2);
	}
	else
		return (t);
}

char		*alignment_mfw(t_flg *lst, char *t, t_or *u)
{
	char	*new;
	int		x;

	x = lst->m_fw - ft_strlen(t);
	if (((lst->m_fw > lst->prc) || ('c' == lst->type || 's' == lst->type ||
			'S' == lst->type || 'C' == lst->type)) && x > 0 && lst->minus == 0)
	{
		new = ft_realloc(&t, x, u);
		t = new;
		if (('c' == lst->type || 'C' == lst->type) && ft_strlen(new) == 0)
			(ft_memmove(new + x, new, 1) && x--);
		else
			ft_memmove(new + x, new, ft_strlen(new));
		t = ft_memset(t, ' ', x);
	}
	else if (lst->minus == 1 && lst->m_fw > 0 && x > -1)
	{
		new = ft_realloc(&t, x, u);
		t = new;
		new = ft_memset(new + (('c' == lst->type || 'C' == lst->type) &&
						ft_strlen(t) == 0 ? 1 : ft_strlen(t)), ' ', x);
	}
	return (t);
}

int			ft_addsign_condition(t_flg *lst, char *t, t_or *u)
{
	if ((lst->type == 'p' || ((lst->type == 'x' || lst->type == 'X' ||
			lst->type == 'o' || lst->type == 'O') && u->arr != 0 &&
			lst->oct == 1) || ((lst->type == 'd' || lst->type == 'i' ||
			lst->type == 'D') && lst->sign > 0)) && *t != '-')
		return (1);
	else
		return (0);
}
