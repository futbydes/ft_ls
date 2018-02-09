/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstprint_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:01:09 by vludan            #+#    #+#             */
/*   Updated: 2018/02/09 15:54:45 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*ls_lstprint_name(t_list *lst, t_flags *flg)
{
	struct winsize	ws;
	int				i;

	if (flg->l != 1 && flg->g != 1 && flg->one != 1)
	{
		ioctl(0, TIOCGWINSZ, &ws);
		i = ws.ws_col / flg->linesize;
		ls_lstcolmn(lst, flg, i);
		return (0);
	}
	else
		ft_printf("%s", lst->name);
	return (lst);
}

void				ls_lstcolmn(t_list *lst, t_flags *flg, int c)
{
	t_list			*head;
	int				n;
	int				x;
	int				a;

	head = lst;
	n = ls_lstcount(lst);
	lst = head;
	c == 0 ? c++ : 0;
	x = n / c;
	a = x;
	while (lst != 0 && (x-- + 1))
	{
		while (lst != 0)
		{
			n = a;
			ft_printf("%-*s ", flg->linesize, lst->name);
			while (lst != 0 && (n-- + 1))
				lst = lst->next;
		}
		head = head->next;
		lst = head;
		ft_printf("\n");
	}
}

int					ls_lstcount(t_list *lst)
{
	int				x;

	x = 0;
	while (lst != 0 && ++x)
		lst = lst->next;
	return (x);
}
