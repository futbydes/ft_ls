/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:23:49 by vludan            #+#    #+#             */
/*   Updated: 2018/01/30 14:40:20 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_memarrchr(char *arr, char *arr2)
{
	int			x;

	x = 1;
	while (arr2[x] != 0)
	{
		if (!(ft_memchr(arr, arr2[x], (int)ft_strlen(arr))))
			return (0);
		x++;
	}
	return (1);
}

void			flag_strct(char *arr, t_flags *flg)
{
	int			x;

	x = 1;
	while ((int)ft_strlen(arr) > x)
	{
		arr[x] == 'R' ? flg->R = 1 : 0;
		arr[x] == 'l' ? flg->l = 1 : 0;
		arr[x] == 'a' ? flg->a = 1 : 0;
		arr[x] == 'r' ? flg->r = 1 : 0;
		arr[x] == 't' ? flg->t = 1 : 0;
		arr[x] == 'u' ? flg->u = 1 : 0;
		arr[x] == 'f' ? flg->f = 1 : 0;
		arr[x] == 'g' ? flg->g = 1 : 0;
		arr[x] == 'd' ? flg->d = 1 : 0;
		arr[x] == 's' ? flg->s = 1 : 0;
		x++;
	}
}

int				flags_parser(int argc, char **argv, t_flags *flg)
{
	int			y;
	char		*flags;

	y = 1;
	flags = ft_memalloc(11);
	ft_strcpy(flags, "Rlartufgds");
	while (argc > y && argv[y][0] == '-' && argv[y][1] != '-')
	{
		if (!(ft_memarrchr(flags, argv[y])))
			return (0);
		flag_strct(argv[y], flg);
		y++;
	}
	free(flags);
	return (1);
}

void			path_parser(int	argc, char **argv, t_flags *flg)
{
	int			y;
	int			x;

	x = 0;
	y = 1;
	while (argv[y] != 0 && argv[y][0] == '-' && argv[y][1] != '-')
		y++;
	if (argc > y && argv[y][0] == '-' && argv[y][1] == '-')
		y += 3;
	flg->path = ft_memalloc((argc - y + 1) * 8);
	argc == y ? flg->path[x] = ft_memalloc(2) : 0;
	argc == y ? ft_strcpy(flg->path[x], ".") : 0;
	while (argv[y] != 0)
	{
		flg->path[x] = ft_memalloc(ft_strlen(argv[y]) + 1);
		ft_strcpy(flg->path[x], argv[y]);
		x++;
		y++;
	}
	flg->path[(x == 0 ? 1 : x)] = ft_memalloc(1);
}

int				main(int argc, char **argv)
{
	t_flags		*flg;

	flg = ft_memalloc(sizeof(t_flags));
	if (argc == 1)
		scan_dir(".", flg);
	else
	{
		flags_parser(argc, argv, flg);
		path_parser(argc, argv, flg);
		main_conv(flg);
	} 
	free(flg);
	return (0);
}
