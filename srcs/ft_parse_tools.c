/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:56:38 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/30 20:42:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				check_validity_dir(DIR *dir, char *directory)
{
	if ((dir = opendir(directory)))
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

t_argf			*push_argf(t_argf *argf, char *str, t_opt *opt, t_dir *dir)
{
	argf = (!argf) ? new_argf(str) : get_argf(argf, str);
	fill_argf(opt, argf, dir);
	return (argf);
}

t_argd			*push_argd(t_argd *argd, char *str, t_dir *dir)
{
	argd = (!argd) ? new_argd(str) : get_argd(argd, str);
	argd->valid = (check_validity_dir(dir->dirp, str)) ? 1 : 0;
	return (argd);
}

char			**init_parse_argv(int i, char **argv, t_dir *dir, t_opt *opt)
{
	init_max(dir);
	i = jump_opts(argv, i);
	check_str_empty(&(argv[i]));
	if (!argv[i])
		return (NULL);
	if (!opt->f)
	{
		ft_sort_ascii_tab(&(argv[i]));
	}
	return (&(argv[i]));
}

void			check_argd(t_argd *argd, t_argf *argf, t_dir *dir, t_opt *opt)
{
	(!argf && !argd) ? exit(1) : 0;
	if (argf)
		treat_files(argf, opt, dir);
	if (!argd)
		exit(1);
	if (list_argd_size(argd) > 1 || ((list_argd_size(argd) == 1) && argf) || \
		dir->flag_error)
	{
		argd->dojump = 1;
		if (argf)
			write(1, "\n", 1);
	}
	(argf) ? destroy_argf(&argf) : 0;
}
