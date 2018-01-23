/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:41:08 by vludan            #+#    #+#             */
/*   Updated: 2017/11/05 18:41:11 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*temp;
	size_t	tmp;
	int		x;
	int		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0' && ((temp = (char*)big)) && (len))
	{
		i = 0;
		x = 0;
		tmp = len;
		while ((little[i++] == big[x++]) && (tmp))
		{
			if (little[i] == '\0')
				return (temp);
			tmp--;
		}
		big++;
		len--;
	}
	return (0);
}
