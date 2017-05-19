/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_r_maj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:21:59 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/08 15:22:06 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				is_parent_dir(char *dir)
{
	return ((ft_strequ(dir, ".") || ft_strequ(dir, "..")) ? 1 : 0);
}

void			opt_r_maj(t_argf *argf, t_opt *opt)
{
	t_argd		*rec;

	rec = NULL;
	argf = (opt->r && !opt->f) ? tail_argf_ptr(argf) : head_argf_ptr(argf);
	while (argf)
	{
		if (argf->data->rights[0] == 'd')
		{
			if (!(is_parent_dir(ft_strrchr(argf->data->arg, '/') + 1)))
			{
				if (show_hide(opt, ft_strrchr(argf->data->arg, '/') + 1))
				{
					rec = new_argd(argf->data->arg);
					multiput("\n", argf->data->arg, ":\n", NULL);
					ft_ls(opt, rec);
					destroy_argd(&rec);
				}
			}
		}
		argf = (opt->r && !opt->f) ? argf->prev : argf->next;
	}
}
