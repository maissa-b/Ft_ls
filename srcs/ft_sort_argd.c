/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_argd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:16:41 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/02 19:16:51 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			dir_swap(t_argd *argd1, t_argd *argd2)
{
	if (argd1 && argd2)
	{
		(argd1->prev) ? argd1->prev->next = argd2 : 0;
		(argd2->next) ? argd2->next->prev = argd1 : 0;
		argd1->next = argd2->next;
		argd2->prev = argd1->prev;
		argd2->next = argd1;
		argd1->prev = argd2;
	}
}

t_argd			*head_argd_ptr(t_argd *argd)
{
	if (argd && argd->prev)
	{
		while (argd->prev)
		{
			if (argd->prev)
				argd = argd->prev;
		}
	}
	return (argd);
}

t_argd			*tail_argd_ptr(t_argd *argd)
{
	if (argd)
	{
		while (argd->next)
		{
			if (argd->next)
				argd = argd->next;
		}
	}
	return (argd);
}

t_argd			*sort_time_dir(t_argd *argd)
{
	t_argd		*tmp;

	tmp = argd;
	while (tmp && tmp->next)
	{
		if (tmp->timer < tmp->next->timer)
		{
			dir_swap(tmp, tmp->next);
			tmp = head_argd_ptr(argd);
		}
		else if (tmp->timer == tmp->next->timer)
		{
			if (ft_strlexicocmp(tmp->arg, tmp->next->arg) > 1)
			{
				dir_swap(tmp, tmp->next);
				tmp = head_argd_ptr(argd);
			}
			else
				tmp = (tmp->next) ? tmp->next : tmp;
		}
		else
			tmp = (tmp->next) ? tmp->next : tmp;
	}
	return (argd);
}
