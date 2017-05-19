/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:59:23 by maissa-b          #+#    #+#             */
/*   Updated: 2016/01/02 21:09:30 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int					is_opt_file(char *file)
{
	return ((file[0] == '-' && file[1] && file[1] != '-') ? 1 : 0);
}

int					is_old(t_dir *dir, int f_time)
{
	return (((dir->actual_t - f_time) > 15768000) ? 1 : 0);
}

int					jump_opts(char **av, int i)
{
	if (av[i])
	{
		if (is_opt_file(av[i]))
			while (av[i] && is_opt_file(av[i]))
				i++;
		if (ft_strnequ("--", av[i], 2))
			(av[i][2] != '\0') ? ls_illegal_option('-') : i++;
	}
	return (i);
}

static	char		special_parse_time(char c, char *s, int flag, int index)
{
	if (flag && (ft_strcmp((s + 24), "07051")) < 0)
		c = s[index + 12];
	else if (flag && (ft_strcmp((s + 24), "07051")) > 0)
		c = s[index + 17];
	else
		c = s[index + 4];
	return (c);
}

char				*parse_time(t_opt *opt, t_dir *dir, time_t timer)
{
	char			*ret;
	char			*date;
	int				i;
	int				j;

	date = ft_strdup(ctime(&timer));
	i = -1;
	j = -1;
	dir->flag = (is_old(dir, timer)) ? 1 : 0;
	if (opt->t_maj)
		ret = (dir->flag && (ft_strcmp((date + 24), "07051")) > 0) ? \
	ft_strsub(date, 4, 25) : ft_strsub(date, 4, 20);
	else
	{
		ret = ft_strnew(13);
		while (++i < 7)
			ret[i] = date[i + 4];
		while (++j < 5)
		{
			ret[i] = special_parse_time(ret[i], date, dir->flag, i);
			i++;
		}
	}
	ft_strdel(&date);
	return (ret);
}
