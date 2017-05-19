/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:34:18 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/05 15:41:41 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			error_dir_unavailable(char *str, char *file)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void			error_file_not_found(char *str, char *file, t_dir *dir)
{
	dir->flag_error = 1;
	ft_putstr_fd(str, 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void			check_str_empty(char **av)
{
	int			i;

	i = -1;
	while (av[++i])
	{
		if (ft_iseof(av[i][0]))
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			exit(1);
		}
	}
}
