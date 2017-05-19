/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_optl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:52:49 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/12 16:52:59 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		aff_aft_str(int max, int len, char *str)
{
	ft_after_str(' ', (max - len), str);
}

void		aff_aft_nbr(int max, int len, int nbr)
{
	ft_after_nbr(' ', (max - len), nbr);
}

void		aff_bef_str(int max, int len, char *str)
{
	ft_before_str(' ', (max - len), str);
}

void		aff_bef_nbr(int max, int len, int nbr)
{
	ft_before_nbr(' ', (max - len), nbr);
}
