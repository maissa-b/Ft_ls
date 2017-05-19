/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argf_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:27:08 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/30 20:39:03 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static	t_dir		*get_max_special(t_data *data, t_dir *dir)
{
	(dir->max_minor < ft_intlen(data->minor)) ? \
	dir->max_minor = ft_intlen(data->minor) : 0;
	(dir->max_major < ft_intlen(data->major)) ? \
	dir->max_major = ft_intlen(data->major) : 0;
	return (dir);
}

t_argf				*head_argf_ptr(t_argf *argf)
{
	if (argf && argf->prev)
	{
		while (argf->prev)
		{
			if (argf->prev)
				argf = argf->prev;
		}
	}
	return (&(*argf));
}

t_argf				*tail_argf_ptr(t_argf *argf)
{
	if (argf)
	{
		while (argf->next)
		{
			if (argf->next)
				argf = argf->next;
		}
	}
	return (argf);
}

void				get_max_argf(t_opt *opt, t_data *data, t_dir *dir)
{
	char			*str;

	str = (ft_strchr(data->arg, '/')) ? ft_strdup(ft_strrchr(data->arg, '/')\
	+ 1) : ft_strdup(data->arg);
	if (show_hide(opt, str) == 1)
	{
		(dir->max_blk < ft_intlen(data->n_blk)) \
		? dir->max_blk = ft_intlen(data->n_blk) : 0;
		(dir->max_rights < (int)ft_strlen(data->rights)) \
		? dir->max_rights = ft_strlen(data->rights) : 0;
		(dir->max_hlnk < ft_intlen(data->n_hlnk)) \
		? dir->max_hlnk = ft_intlen(data->n_hlnk) : 0;
		(dir->max_uid < (int)ft_strlen(data->uid)) \
		? dir->max_uid = ft_strlen(data->uid) : 0;
		(dir->max_gid < (int)ft_strlen(data->gid)) \
		? dir->max_gid = ft_strlen(data->gid) : 0;
		if (data->rights[0] == 'b' || data->rights[0] == 'c')
			dir = get_max_special(data, dir);
		else
			(dir->max_bytes < ft_intlen(data->bytes)) ? \
		dir->max_bytes = ft_intlen(data->bytes) : 0;
		(dir->max_date < (int)ft_strlen(data->date)) \
		? dir->max_date = ft_strlen(data->date) : 0;
	}
	ft_strdel(&str);
}

void				fill_argf(t_opt *opt, t_argf *argf, t_dir *dir)
{
	struct passwd	*psw;
	struct group	*grp;

	lstat(argf->data->arg, &dir->sb);
	argf->data->n_blk = dir->sb.st_blocks;
	argf->data->rights = get_perm(dir, argf->data->arg);
	argf->data->n_hlnk = dir->sb.st_nlink;
	if ((psw = getpwuid(dir->sb.st_uid)))
		argf->data->uid = ft_strdup(psw->pw_name);
	else
		argf->data->uid = ft_itoa(dir->sb.st_uid);
	if ((grp = getgrgid(dir->sb.st_gid)))
		argf->data->gid = ft_strdup(grp->gr_name);
	else
		argf->data->gid = ft_itoa(dir->sb.st_gid);
	if (argf->data->rights[0] == 'b' || argf->data->rights[0] == 'c')
		ope_minor_major(argf, dir);
	else
		argf->data->bytes = dir->sb.st_size;
	argf->data->timer = dir->sb.st_mtime;
	argf->data->date = ft_strdup(ctime(&argf->data->timer));
	get_max_argf(opt, argf->data, dir);
}
