/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:29:11 by vludan            #+#    #+#             */
/*   Updated: 2018/02/08 12:52:06 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_intlen(intmax_t i)
{
	int	n;

	n = 0;
	while (i)
	{
		i = i / 10;
		n++;
	}
	return (n);
}
