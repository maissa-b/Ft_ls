/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_argf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:42:09 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/30 20:38:22 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t			list_size(t_argf *list)
{
	size_t		len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void			link_swap(t_argf **l1, t_argf **l2)
{
	t_data		*temp;

	temp = (*l1)->data;
	(*l1)->data = (*l2)->data;
	(*l2)->data = temp;
}

t_argf			*new_argf(char *name)
{
	t_argf		*new;
	struct stat	stats;

	new = NULL;
	if (name && ((new = malloc(sizeof(t_argf)))))
	{
		new->data = malloc(sizeof(t_data));
		lstat(name, &stats);
		new->next = NULL;
		new->prev = NULL;
		new->data->n_blk = 0;
		new->data->rights = NULL;
		new->data->n_hlnk = 0;
		new->data->uid = NULL;
		new->data->gid = NULL;
		new->data->bytes = 0;
		new->data->timer = (lstat(name, &stats) == 0) ? stats.st_mtime : 0;
		new->data->date = NULL;
		new->data->minor = 0;
		new->data->major = 0;
		new->data->arg = ft_strdup(name);
	}
	return (new);
}

t_argf			*get_argf(t_argf *argf, char *argv)
{
	t_argf		*elem;

	elem = argf;
	if (argv)
	{
		elem = new_argf(argv);
		elem->prev = argf;
		argf->next = elem;
		argf = argf->next;
	}
	return (argf);
}
