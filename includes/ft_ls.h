/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 21:10:08 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/23 12:37:55 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <grp.h>
# include <libft.h>
# include <pwd.h>
# include <stdio.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <uuid/uuid.h>

# define OPTS "1RTafgloprst"
# define SPE_YEAR "7051"
# define SIX_MONTH 15768000

/*
**	data list :
*/

typedef struct		s_data
{
	char			*arg;
	int				isdir;
	int				valid;
	int				dojump;
	int				n_blk;
	char			*rights;
	int				n_hlnk;
	char			*uid;
	char			*gid;
	int				bytes;
	char			*date;
	time_t			timer;
	int				f_len;
	int				minor;
	int				major;
	dev_t			dev;
}					t_data;

/*
**	argv list :
*/

typedef struct		s_argd
{
	struct s_argd	*next;
	struct s_argd	*prev;
	char			*arg;
	int				isdir;
	int				valid;
	int				dojump;
	char			*rights;
	time_t			timer;
}					t_argd;

/*
**	files list :
*/

typedef struct		s_argf
{
	t_data			*data;
	struct s_argf	*next;
	struct s_argf	*prev;
}					t_argf;

/*
**	struct options :
*/

typedef	struct		s_opt
{
	int				a;
	int				f;
	int				g;
	int				l;
	int				t;
	int				r;
	int				o;
	int				p;
	int				s;
	int				r_maj;
	int				t_maj;
}					t_opt;

/*
**	struct dir :
*/

typedef struct		s_dir
{
	DIR				*dirp;
	struct dirent	*sd;
	struct stat		sb;
	char			*path;
	char			*date;
	int				flag;
	int				flag_error;
	int				max_blk;
	int				max_rights;
	int				max_hlnk;
	int				max_uid;
	int				max_gid;
	int				max_bytes;
	int				max_date;
	int				max_file;
	int				max_rdev;
	int				max_major;
	int				max_minor;
	int				actual_t;
}					t_dir;

/*
**	ft_init.c :
*/

void				init_options(t_opt *opt);
void				init_max(t_dir *dir);

/*
**	ft_parse.c :
*/

void				treat_files(t_argf *argf, t_opt *op, t_dir *dir);
void				treat_files_dir(t_argf *argf, t_opt *op, t_dir *dir);
t_argd				*ft_parse_argv(t_opt *opt, t_argd *argd, char **av);

/*
**	ft_parse_tools.c :
*/

int					check_validity_dir(DIR *dir, char *directory);
t_argf				*push_argf(t_argf *argf, char *str, t_opt *opt, t_dir *dir);
t_argd				*push_argd(t_argd *argd, char *str, t_dir *dir);
char				**init_parse_argv(int i, char **av, t_dir *dir, t_opt *opt);
void				check_argd(t_argd *ad, t_argf *af, t_dir *dir, t_opt *opt);

/*
**	ft_errors.c :
*/

void				error_dir_unavailable(char *str, char *file);
void				error_file_not_found(char *str, char *file, t_dir *dir);
void				check_str_empty(char **av);
/*
**	ft_destroy.c :
*/

void				destroy_argf(t_argf **head);
void				destroy_argd(t_argd **head);

/*
**	ft_opt.c :
*/

void				opt_s(t_dir *dir, t_data *data);
void				is_opt_p(t_argf *argf, t_opt *op);
void				is_opt(t_opt *opt, char *file);
/*
**	ft_opt_tools.c :
*/

int					is_opt_file(char *file);
int					is_old(t_dir *dir, int f_time);
int					jump_opts(char **av, int i);
char				*parse_time(t_opt *opt, t_dir *dir, time_t timer);

/*
**	ft_opt_l.c :
*/

char				*get_perm(t_dir *dir, char *str);
void				put_symblnk(char *str, t_dir *dir);
void				put_symblnk_dir(char *str, t_dir *dir);
void				opt_l_files(t_data *data, t_opt *opt, t_dir *dir);
void				opt_l_dir(t_argf *af, t_data *da, t_opt *opt, t_dir *dir);

/*
**	ft_aff_optl.c:
*/

void				aff_aft_str(int max, int len, char *str);
void				aff_aft_nbr(int max, int len, int nbr);
void				aff_bef_str(int max, int len, char *str);
void				aff_bef_nbr(int max, int len, int nbr);

/*
**	ft_opt_r_maj.c:
*/

int					is_parent_dir(char *dir);
void				opt_r_maj(t_argf *argf, t_opt *opt);

/*
**	ft_rights_tools.c :
*/

char				check_uid_bit(t_dir *dir);
char				check_gid_bit(t_dir *dir);
char				check_sticky_bit(t_dir *dir);
char				get_extented_attributes(char *str);
char				check_type_file(t_dir *dir);

/*
**	ft_sort_argd.c :
*/

void				dir_swap(t_argd *argd1, t_argd *argd2);
t_argd				*head_argd_ptr(t_argd *argd);
t_argd				*tail_argd_ptr(t_argd *argd);
t_argd				*sort_time_dir(t_argd *argd);

/*
**	ft_sort_argf.c :
*/

void				list_sort(t_argf **list, t_opt *opt);

/*
**	ft_list_argd.c :
*/

int					list_argd_size(t_argd *argd);
t_argd				*new_argd(char *name);
t_argd				*get_argd(t_argd *argd, char *argv);

/*
**	ft_list_argf.c :
*/

size_t				list_size(t_argf *list);
void				link_swap(t_argf **l1, t_argf **l2);
t_argf				*new_argf(char *name);
t_argf				*get_argf(t_argf *argf, char *argv);

/*
**	ft_tools.c :
*/

int					show_hide(t_opt *opt, char *str);
int					longf_opt(t_opt *opt);
void				ls_illegal_option(char character);
void				multiput(char *str1, char *str2, char *str3, char *str4);
void				aff_error(char *str1, char *str2, char *str3);

/*
**	ft_tools2.c :
*/

void				print_minor_major(t_dir *dir, int minor, int major);
void				ope_minor_major(t_argf *argf, t_dir *dir);
void				aff_invalid_path(t_dir *dir, char *file);
int					is_valid(struct stat *stats, char *file);
t_opt				*check_argv_opt(t_opt *opt, char **argv);

/*
**	ft_argf_tools.c :
*/

t_argf				*head_argf_ptr(t_argf *argf);
t_argf				*tail_argf_ptr(t_argf *argf);
void				get_max_argf(t_opt *opt, t_data *data, t_dir *dir);
void				fill_argf(t_opt *opt, t_argf *argf, t_dir *dir);

/*
**	ft_argd_tools.c :
*/

void				put_total_blocs(t_argf *argf, t_opt *opt);

/*
**	ft_ls.c :
*/

void				ft_ls(t_opt *opt, t_argd *argd);
void				exec_ls(t_opt *opt, t_argd *argd);

#endif
