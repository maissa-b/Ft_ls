/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argd_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:17:13 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/05 16:35:46 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			put_total_blocs(t_argf *argf, t_opt *opt)
{
	t_argf		*tmp;
	int			total;
	int			flag;

	total = 0;
	flag = 0;
	if (argf && argf->data->arg)
	{
		tmp = head_argf_ptr(argf);
		while (tmp)
		{
			if (show_hide(opt, (ft_strrchr(tmp->data->arg, '/') + 1)))
			{
				total += tmp->data->n_blk;
				flag++;
			}
			tmp = tmp->next;
		}
		if (flag != 0)
		{
			ft_putstr("total ");
			ft_putnbr(total);
			write(1, "\n", 1);
		}
	}
}
