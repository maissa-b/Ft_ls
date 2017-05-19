/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 19:59:26 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/17 19:59:42 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		init_options(t_opt *opt)
{
	opt->a = 0;
	opt->f = 0;
	opt->g = 0;
	opt->l = 0;
	opt->t = 0;
	opt->r = 0;
	opt->o = 0;
	opt->p = 0;
	opt->s = 0;
	opt->r_maj = 0;
	opt->t_maj = 0;
}

void		init_max(t_dir *dir)
{
	dir->flag = 0;
	dir->flag_error = 0;
	dir->max_blk = 0;
	dir->path = NULL;
	dir->max_rights = 0;
	dir->max_hlnk = 0;
	dir->max_uid = 0;
	dir->max_gid = 0;
	dir->max_bytes = 0;
	dir->max_date = 0;
	dir->max_major = 0;
	dir->max_minor = 0;
	dir->actual_t = time(NULL);
}
