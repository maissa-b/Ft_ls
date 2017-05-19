/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_argf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:35:38 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/31 18:54:13 by ransidei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static	time_t	list_cmp_ascii(t_data *f1, t_data *f2)
{
	return (ft_strcmp(f1->arg, f2->arg));
}

static	time_t	list_cmp_time(t_data *f1, t_data *f2)
{
	return ((f2->timer - f1->timer));
}

static	char	loop(int i, char c, t_argf *af, time_t (*f)(t_data *, t_data *))
{
	int			j;

	j = 0;
	c = 0;
	while (j++ < (i - 1))
	{
		if (f(af->data, af->next->data) > 0)
		{
			link_swap(&af, &af->next);
			c = 1;
		}
		af = af->next;
	}
	return (c);
}

static	void	list_sorting(t_argf **list, time_t (*cmp)(t_data *, t_data *))
{
	t_argf		*tmp;
	size_t		len;
	char		modified;

	len = 0;
	tmp = *list;
	while (*list)
	{
		len++;
		(*list) = (*list)->next;
	}
	*list = head_argf_ptr(tmp);
	modified = 1;
	while (modified == 1)
	{
		modified = loop(len, modified, tmp, cmp);
		tmp = *list;
	}
}

void			list_sort(t_argf **list, t_opt *opt)
{
	list_sorting(list, &list_cmp_ascii);
	if (opt->t)
	{
		list_sorting(list, &list_cmp_time);
	}
}
