/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:31:44 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/02 17:38:45 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_argf			*read_argd(t_argf *argf, t_argd *argd, t_opt *opt, t_dir *dir)
{
	char		*path;

	path = NULL;
	if ((dir->dirp = opendir(argd->arg)))
	{
		while ((dir->sd = readdir(dir->dirp)))
		{
			if (ft_strequ(argd->arg, "/"))
				path = ft_strjoin(argd->arg, dir->sd->d_name);
			else
				path = ft_multijoin(path, argd->arg, "/", dir->sd->d_name);
			lstat(path, &dir->sb);
			argf = (!argf) ? new_argf(path) : get_argf(argf, path);
			fill_argf(opt, argf, dir);
			ft_strdel(&path);
		}
		closedir(dir->dirp);
	}
	return (head_argf_ptr(argf));
}

void			read_ls(t_argf *argf, t_opt *opt, t_dir *dir)
{
	if (argf)
	{
		if (!opt->f)
			list_sort(&argf, opt);
		treat_files_dir(argf, opt, dir);
	}
	(argf) ? destroy_argf(&argf) : 0;
}

void			ft_ls(t_opt *opt, t_argd *argd)
{
	t_argf		*argf;
	t_dir		dir;

	init_max(&dir);
	argf = NULL;
	if (argd->valid != 1 && !ft_strequ(argd->arg, ".") && argd->isdir == 1)
		error_dir_unavailable("ls: ", argd->arg);
	else
	{
		argf = read_argd(argf, argd, opt, &dir);
		read_ls(argf, opt, &dir);
	}
	ft_bzero(&dir, sizeof(&dir));
}

void			exec_ls(t_opt *op, t_argd *ad)
{
	if (ad && ad->arg)
	{
		if (list_argd_size(ad) < 2 && !ad->dojump)
			ft_ls(op, ad);
		else
		{
			ad = (op->r && !op->f) ? tail_argd_ptr(ad) : head_argd_ptr(ad);
			while (ad)
			{
				if ((op->r && ad != tail_argd_ptr(ad)) || \
						(!op->r && ad != head_argd_ptr(ad)))
				{
					write(1, "\n", 1);
				}
				multiput(ad->arg, ":\n", NULL, NULL);
				ft_ls(op, ad);
				ad = (op->r && !op->f) ? ad->prev : ad->next;
			}
		}
	}
}

int				main(int ac, char **av)
{
	t_opt		*opt;
	t_argd		*argd;

	argd = NULL;
	(void)ac;
	if (av && *av)
	{
		if ((opt = malloc(sizeof(t_opt))))
		{
			init_options(opt);
			opt = check_argv_opt(opt, av);
			if (!(argd = ft_parse_argv(opt, argd, (av + 1))))
				argd = new_argd(".");
			if (opt->t && !opt->f)
				argd = sort_time_dir(head_argd_ptr(argd));
			exec_ls(opt, head_argd_ptr(argd));
			free(opt);
		}
	}
	return (0);
}
