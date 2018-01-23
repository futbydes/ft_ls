/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:06:39 by vludan            #+#    #+#             */
/*   Updated: 2017/11/06 13:32:28 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	char	*temp;
	int		x;
	int		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		x = 0;
		i = 0;
		temp = (char*)big;
		while ((little[i] == big[x]) || (little[i] == '\0'))
		{
			if ((little[i] == '\0') || (big[x] == '\0'))
				return (temp);
			x++;
			i++;
		}
		big++;
	}
	return (0);
}
