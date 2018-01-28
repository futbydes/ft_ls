/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:50:51 by vludan            #+#    #+#             */
/*   Updated: 2018/01/28 11:47:34 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h> //openreadcloseDIR
# include <stdlib.h> //exit
# include <unistd.h> //statlstat
# include <sys/types.h> //getpwuid
# include <sys/stat.h>
# include <stdio.h> //perror
# include <string.h> //strerror

typedef struct s_flags {
	char	R;
	char	l;
	char	a;
	char	r;
	char	t;
	char	u;
	char	f;
	char	g;
	char	d;
	char	**path;
}			t_flags;

typedef struct			s_list 
{
	char				*name;
	unsigned short		st_mode;
	struct s_list		*next;
}						t_list;

void		*ft_memalloc(size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			flags_parser(int argc, char **argv, t_flags *flg);
void		path_parser(int	argc, char **argv, t_flags *flg);
void		flag_strct(char *arr, t_flags *flg);
int			ft_memarrchr(char *arr, char *arr2);
t_list		*scan_dir(char *arg, t_flags *flg);
void		main_conv(t_flags *flg);
void		recursive_dir_scan(char *path, t_flags *flg);
void		ls_lstprint(t_list *head);
t_list      *ls_lstnew(t_list *head, char *name, struct stat *stat, t_flags *flg);
t_list		*ls_lstsort(t_list *head, t_flags *flg);
t_list		*ls_lstbubsort_alpha(t_list **lst_m);
void		ft_lstswap(t_list **head, t_list **swp);
void		ls_lstrev(t_list **head);
t_list		*ls_lstpushup(t_list *lst, t_list *temp);
char		*ls_pathmaker(char *path, char *new_fld);


//err_usage;
//err_nsf;
//std_ls;
//recursive_dir_scan;

#endif
