/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:14 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/05 18:45:19 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			treat_files(t_argf *argf, t_opt *op, t_dir *dir)
{
	char		*tmp;

	(op->t && !op->f) ? list_sort(&argf, op) : 0;
	argf = (op->r && !op->f) ? tail_argf_ptr(argf) : head_argf_ptr(argf);
	while (argf)
	{
		tmp = (ft_strchr(argf->data->arg, '/')) ? \
		ft_strdup(ft_strrchr(argf->data->arg, '/') + 1) : \
		ft_strdup(argf->data->arg);
		if (show_hide(op, tmp))
		{
			(op->s) ? opt_s(dir, argf->data) : 0;
			longf_opt(op) ? opt_l_files(argf->data, op, dir) : \
			ft_putendl(argf->data->arg);
		}
		ft_strdel(&tmp);
		argf = (op->r && !op->f) ? argf->prev : argf->next;
	}
	argf = head_argf_ptr(argf);
}

static	int		loop_treat_files_dir(t_argf *af, t_dir *dir, t_opt *op, int i)
{
	char		*tmp;

	tmp = NULL;
	tmp = ft_strdup(ft_strrchr(af->data->arg, '/') + 1);
	if (show_hide(op, tmp))
	{
		(op->s) ? opt_s(dir, af->data) : 0;
		if (af && af->data->arg)
		{
			if (longf_opt(op))
				opt_l_dir(af, af->data, op, dir);
			else
				is_opt_p(af, op);
		}
	}
	ft_strdel(&tmp);
	if (op->r_maj && af->data->rights[0] == 'd')
	{
		if (!(is_parent_dir(ft_strrchr(af->data->arg, '/') + 1)))
			i = 1;
	}
	return (i);
}

void			treat_files_dir(t_argf *argf, t_opt *op, t_dir *dir)
{
	t_argf		*head;
	int			flag;

	head = argf;
	flag = 0;
	(op->s || (!op->s && longf_opt(op))) ? put_total_blocs(argf, op) : 0;
	argf = (op->r && !op->f) ? tail_argf_ptr(argf) : head_argf_ptr(argf);
	while (argf)
	{
		flag = loop_treat_files_dir(argf, dir, op, flag);
		argf = (op->r && !op->f) ? argf->prev : argf->next;
	}
	argf = head_argf_ptr(argf);
	if (head && flag && op->r_maj)
		opt_r_maj(head, op);
}

t_argd			*ft_parse_argv(t_opt *opt, t_argd *argd, char **av)
{
	t_dir		dir;
	int			i;
	t_argf		*argf;

	i = 0;
	argf = NULL;
	if ((av = init_parse_argv(i, av, &dir, opt)) == NULL)
		return (NULL);
	while (av[i])
	{
		if ((lstat(av[i], &dir.sb)) == 0)
		{
			if ((S_ISDIR(dir.sb.st_mode)) || ((S_ISLNK(dir.sb.st_mode)) && \
				opendir(av[i]) && !longf_opt(opt)))
				argd = push_argd(argd, av[i], &dir);
			else
				argf = push_argf(argf, av[i], opt, &dir);
		}
		else
			error_file_not_found("ls: ", av[i], &dir);
		i++;
	}
	check_argd(argd, argf, &dir, opt);
	return (argd);
}
