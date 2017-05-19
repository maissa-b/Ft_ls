/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 18:47:41 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/03 16:23:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void				print_minor_major(t_dir *dir, int minor, int major)
{
	ft_before_nbr(' ', (dir->max_major - ft_intlen(major)) + 2, major);
	write(1, ", ", 2);
	ft_before_nbr(' ', (dir->max_minor - ft_intlen(minor)), minor);
}

void				ope_minor_major(t_argf *argf, t_dir *dir)
{
	argf->data->minor = minor(dir->sb.st_rdev);
	argf->data->major = major(dir->sb.st_rdev);
}

void				aff_invalid_path(t_dir *dir, char *file)
{
	if (dir->sb.st_mode && file)
		aff_error("ft_ls: ", file, ": permission denied");
	else
		aff_error("ft_ls: ", file, ": no such file or directory");
}

int					is_valid(struct stat *stats, char *file)
{
	DIR				*dirp;

	lstat(file, stats);
	if (stats->st_mode && file)
	{
		if (S_ISDIR(stats->st_mode))
		{
			if (!(dirp = opendir(file)))
				return (0);
			closedir(dirp);
			return (1);
		}
	}
	return (0);
}

t_opt				*check_argv_opt(t_opt *opt, char **argv)
{
	int				i;

	i = 0;
	if (argv && (argv[1]))
	{
		while (argv[++i])
		{
			if (!is_opt_file(argv[i]))
				break ;
			is_opt(opt, argv[i]);
		}
	}
	return (opt);
}
