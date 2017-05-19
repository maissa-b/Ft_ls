/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:44:09 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/04 13:44:19 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			set_opt(t_opt *opt, char c)
{
	(c == 'a') ? opt->a = 1 : 0;
	(c == 'f') ? opt->f = 1 : 0;
	(c == 'g') ? opt->g = 1 : 0;
	(c == 'l') ? opt->l = 1 : 0;
	(c == 't') ? opt->t = 1 : 0;
	(c == 'r') ? opt->r = 1 : 0;
	(c == 'o') ? opt->o = 1 : 0;
	(c == 'p') ? opt->p = 1 : 0;
	(c == 's') ? opt->s = 1 : 0;
	(c == 'R') ? opt->r_maj = 1 : 0;
	(c == 'T') ? opt->t_maj = 1 : 0;
}

static int			check_opt(t_opt *opt, char c)
{
	int				i;

	i = -1;
	if (OPTS)
	{
		while (OPTS[++i])
		{
			if (c == OPTS[i])
			{
				set_opt(opt, c);
				if (opt->f)
				{
					opt->r = 0;
					opt->t = 0;
				}
				return (1);
			}
		}
	}
	return (0);
}

void				opt_s(t_dir *dir, t_data *data)
{
	ft_before_nbr(' ', (dir->max_blk - ft_intlen(data->n_blk)), data->n_blk);
	write(1, " ", 1);
}

void				is_opt_p(t_argf *argf, t_opt *op)
{
	ft_putstr(ft_strrchr(argf->data->arg, '/') + 1);
	(op->p && argf->data->rights[0] == 'd') ? ft_putendl("/") : ft_putchar(10);
}

void				is_opt(t_opt *opt, char *file)
{
	int				i;

	i = 0;
	if (file)
	{
		while (file[++i])
		{
			if (!(ft_strchr(OPTS, file[i])))
				ls_illegal_option(file[i]);
			else
				check_opt(opt, file[i]);
		}
	}
}
