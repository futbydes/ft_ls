/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:20:45 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:16:59 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r');
}

int			ft_atoi(const char *str)
{
	unsigned long int	n;
	int					x;
	int					c;

	n = 0;
	c = 1;
	x = 0;
	while (ft_whitespace(str[x]))
		x++;
	if (str[x] == '-')
		c = -1;
	if ((str[x] == '+') || (str[x] == '-'))
		x++;
	while ((str[x] != '\0') && (str[x] >= 48) && (str[x] <= 57))
	{
		n = (n * 10 + str[x] - 48);
		if (n >= 9223372036854775807 && c == 1)
			return (-1);
		else if (n > 9223372036854775807 && c == -1)
			return (0);
		x++;
	}
	return ((int)(n * c));
}
