/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:39:40 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/08 15:06:38 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static	void	clear_argf(t_data *data)
{
	ft_strdel(&data->rights);
	ft_strdel(&data->uid);
	ft_strdel(&data->gid);
	ft_strdel(&data->date);
	ft_strdel(&data->arg);
	data->n_blk = 0;
	data->n_hlnk = 0;
	data->minor = 0;
	data->major = 0;
	data->bytes = 0;
	data->timer = 0;
}

static	void	clear_argd(t_argd **argd)
{
	(*argd)->isdir = 0;
	(*argd)->valid = 0;
	(*argd)->dojump = 0;
	(*argd)->timer = 0;
}

void			destroy_argf(t_argf **head)
{
	t_argf		*tmp;

	if (*head && head && (*head)->data)
	{
		*head = head_argf_ptr(*head);
		while (*head)
		{
			clear_argf((*head)->data);
			ft_strdel(&(*head)->data->arg);
			free((*head)->data);
			tmp = (*head)->next;
			free(*head);
			(*head) = tmp;
		}
		*head = NULL;
	}
}

void			destroy_argd(t_argd **head)
{
	t_argd		*tmp;

	if (*head && head)
	{
		while (*head)
		{
			clear_argd(head);
			ft_strdel(&(*head)->arg);
			tmp = (*head)->next;
			free(*head);
			(*head) = tmp;
			free(tmp);
		}
		*head = NULL;
	}
}
