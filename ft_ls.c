/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:23:49 by vludan            #+#    #+#             */
/*   Updated: 2018/01/16 17:35:57 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			recursive_dir_scan(char **argv);

int			ft_memarrchr(char *arr, char *arr2)
{
	int		x;

	x = 1;
	while (arr2[x] != 0)
	{
		if (!(ft_memchr(arr, arr2[x], (int)ft_strlen(arr))))
			return (0);
		x++;
	}
	return (1);
}

void		flag_strct(int argc, char *arr, t_flags *flg)
{
	int		x;

	x = 1;
	while (ft_strlen(arr) > x)
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
		x++;
	}
}

int			flags_parser(int argc, char **argv, t_flags *flg)
{
	int		y;
	char	*flags;

	y = 1;
	flags = ft_memalloc(10);
	ft_strcpy(flags, "Rlartufgd");
	while (argc > y && argv[y][0] == '-')
	{
		if (!(ft_memarrchr(flags, argv[y])))
			return (1);
		flag_strct(argc, argv[y], flg);
		y++;
	}
	free(flags);
	return (0);
}

void		path_parser(int	argc, char **argv, t_flags *flg)
{
	int		y;
	int		x;

	x = 0;
	y = 1;
	while (argv[y] != 0 && argv[y][0] == '-')
		y++;
	if (argc == y)
		flg->path = ft_memalloc(1);
	else
	{
		flg->path = ft_memalloc((argc - y + 1) * 8);
		while (argv[y] != 0)
		{
			flg->path[x] = ft_memalloc(ft_strlen(argv[y]) + 1);
			ft_strcpy(flg->path[x], argv[y]);
			x++;
			y++;
		}
		flg->path[x] = ft_memalloc(1);
	}
}

int				main(int argc, char **argv)
{
	t_flags		*flg;

//	if (argc == 1)
//		std_ls();
//	else
//	{
		flg = ft_memalloc(sizeof(t_flags));
		flags_parser(argc, argv, flg);
		path_parser(argc, argv, flg);
		display_conv(flg);
//	}
	return (0);
}
