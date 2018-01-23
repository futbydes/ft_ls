/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:40:12 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:28:48 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int		x;

	x = 0;
	if ((s1 == 0) || (s2 == 0))
		return (0);
	while ((s1[x] - s2[x] == 0) && ((s1[x] != '\0') || (s2[x] != '\0')))
		x++;
	if ((s1[x] == s2[x]) || ((s1[x] == '\0') && (s2[x] == '\0')))
		return (1);
	else
		return (0);
}
