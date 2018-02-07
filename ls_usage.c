/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:26:43 by vludan            #+#    #+#             */
/*   Updated: 2018/02/07 14:04:24 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_usage(char v)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &v, 1);
	write(2, "\n", 2);
	write(2, "usage: ls [-RlartufgdsT@] [file ...]\n", 40);
	return (1);
}

t_list	*ls_error_msg(char *msg, char *arg)
{
	write(2, "ls: ", 4);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 2);
	return (0);
}
