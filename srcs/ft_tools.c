/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:59:32 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/03 16:22:26 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				show_hide(t_opt *opt, char *str)
{
	return ((str[0] != '.' || opt->a || opt->f) ? 1 : 0);
}

int				longf_opt(t_opt *opt)
{
	return ((opt->l || opt->o || opt->g) ? 1 : 0);
}

void			ls_illegal_option(char character)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar(character);
	ft_putchar(10);
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(OPTS, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(1);
}

void			multiput(char *str1, char *str2, char *str3, char *str4)
{
	(str1) ? ft_putstr(str1) : 0;
	(str2) ? ft_putstr(str2) : 0;
	(str3) ? ft_putstr(str3) : 0;
	(str4) ? ft_putstr(str4) : 0;
}

void			aff_error(char *str1, char *str2, char *str3)
{
	ft_putstr(str1);
	ft_putstr(str2);
	ft_putendl(str3);
}
