/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_argd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:42:32 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/03 16:25:57 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				list_argd_size(t_argd *argd)
{
	int			size;
	t_argd		*tmp;

	size = 0;
	tmp = NULL;
	if (argd)
	{
		tmp = argd;
		while (tmp)
		{
			tmp = tmp->next;
			size++;
		}
		destroy_argd(&tmp);
	}
	return (size);
}

t_argd			*new_argd(char *name)
{
	t_argd		*new;
	struct stat	stats;

	new = NULL;
	if (name && ((new = malloc(sizeof(t_argd)))))
	{
		lstat(name, &stats);
		new->next = NULL;
		new->prev = NULL;
		new->isdir = (S_ISDIR(stats.st_mode)) ? 1 : 0;
		new->timer = (lstat(name, &stats) == 0) ? stats.st_mtime : 0;
		new->valid = (is_valid(&stats, name)) ? 1 : 0;
		new->arg = ft_strdup(name);
	}
	return (new);
}

t_argd			*get_argd(t_argd *argd, char *argv)
{
	t_argd		*elem;

	elem = argd;
	if (argv)
	{
		elem = new_argd(argv);
		elem->prev = argd;
		argd->next = elem;
		argd = argd->next;
	}
	return (argd);
}
