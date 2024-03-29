/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:50:51 by vludan            #+#    #+#             */
/*   Updated: 2018/02/11 11:18:51 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/ioctl.h>

typedef struct			s_flags
{
	char				f_r;
	char				l;
	char				a;
	char				r;
	char				t;
	char				u;
	char				f;
	char				g;
	char				d;
	char				s;
	char				f_t;
	char				ext;
	char				one;
	char				acl;
	int					maxlink;
	int					linesize;
	long int			maxsize;
	long int			maxblock;
	int					totalblock;
	char				**path;
	char				*path_in;
}						t_flags;

typedef struct			s_list
{
	char				*name;
	char				*u_name;
	char				*gr_name;
	unsigned int		major;
	unsigned int		minor;
	unsigned short		st_mode;
	long int			time;
	long int			b_size;
	char				*f_rights;
	int					n_link;
	long long int		f_size;
	char				*xattr;
	struct s_list		*next;
}						t_list;

void					*ft_memalloc(size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strrchr(const char *s, int c);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strjoin(char const *s1, char const *s2);
int						flags_parser(int argc, char **argv, t_flags *flg);
int						path_parser(int	argc, char **argv, t_flags *flg);
void					flag_strct(char *arr, t_flags *flg);
char					ft_memarrchr(char *arr, char *arr2);
t_list					*scan_dir(char *arg, t_flags *flg);
void					main_conv(t_flags *flg);
void					recursive_dir_scan(char *path, t_flags *flg);
t_list					*ls_lstprint(t_list *head, t_flags *flg, char *path);
void					ls_lstprint_a(t_list **head, t_flags *fg, char *path,
		char *buf);
t_list					*ls_lstnew(t_list *head, char *name, struct stat *stat,
		t_flags *flg);
t_list					*ls_lstsort(t_list *head, t_flags *flg);
t_list					*ls_lstbubsort(t_list **lst_m, int mode);
void					ft_lstswap(t_list **head, t_list **swp);
void					ls_lstrev(t_list **head);
void					ls_lstfree(t_list *head, t_flags *flg, int mode);
t_list					*ls_lstpushup(t_list *lst, t_list *temp);
char					*ls_pathmaker(char *path, char *new_fld);
void					ls_xattributes(char *path);
int						ls_acl_attr(char *path, int mode);
void					ls_fdata(t_list *lst, struct stat *stat, t_flags *flg);
void					ls_fdata_r(t_list *lst, struct stat *stat,
		t_flags *flg);
int						ft_intlen(intmax_t i);
void					ls_time(t_list *lst, t_flags *flg);
void					ls_d_conv(char *path, t_flags *flg);
int						ls_usage(char v);
t_list					*ls_error_msg(char *msg, char *arg);
t_list					*ls_lstprint_name(t_list *lst, t_flags *flg);
int						ls_lstcount(t_list *lst);
void					ls_lstcolmn(t_list *lst, t_flags *flg, int c);
int						scan_path(int x, t_flags *flg, struct stat *buf);
int						ft_printf(char *spec, ...);
void					scan_path_op(int x, t_flags *flg, t_list *f_head,
		t_list *head);

#endif
