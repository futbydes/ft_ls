/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:30 by vludan            #+#    #+#             */
/*   Updated: 2018/01/16 19:58:44 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	display_conv(t_flags *flags)
{
}

int		scan_std(t_flags *flg)
{
	if (flg->path == 0)
		scan_dir(".");
}
*/

t_list		lstsort(char *name, t_flags *flg)
{
	t_list	*lst;


}

int			scan_dir(char *arg, t_flags *flg)
{
	DIR 	*dir;
	struct	dirent *dien;

	if (!(dir = opendir(arg)))
		return (0);
	while ((dien = readdir(dir)) != 0)
	{
		if (ft_strcmp(dien->d_name, ".") == 0 || ft_strcmp(dien->d_name, "..") == 0)
			continue ;
		else
		{
			if (dien->d_name[0] == '.' && flg->a == 0)
				continue ;
			printf("%s\n", dien->d_name);
		}
	}
	return (1);
}

