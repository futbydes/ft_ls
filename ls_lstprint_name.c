/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstprint_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:01:09 by vludan            #+#    #+#             */
/*   Updated: 2018/02/08 17:28:41 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ls_lstprint_name(t_list *lst, t_flags *flg, char *buf
		char *path)
{
	struct winsize	ws;
	int				i;
	int				x;

	if (flg->l != 1 && flg->g != 1 && flg->one != 1)
	{
		ioctl(0, TIOCGWINSZ, &ws);
		x = ws.ws_col / ws.ws_row;
		while (x)
		{
			printf("%*s", (ft_, lst->name);
		}
	//	printf(":::%d\n", ws.ws_row);
	//	printf(":::%d\n", ws.ws_col);
		printf("%*s", ws.ws_row, lst->name);
	}
	else
	{
		printf("%s", lst->name);
		if (S_ISLNK(lst->st_mode) && (flg->l || flg->g))
			flg->d == 1 ? readlink(path, buf, 255) :
		readlink(flg->path_in = ls_pathmaker(path, lst->name), buf, 255);
		(S_ISLNK(lst->st_mode) && (flg->l || flg->g)) ? printf(" -> %s", buf) : 0;
		printf("\n");
	}
}