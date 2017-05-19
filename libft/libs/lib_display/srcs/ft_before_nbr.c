/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:20:58 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/11 20:20:59 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_before_nbr(char c, int len, int nbr)
{
	if (len != 0)
		ft_put_n_char(c, len);
	ft_putnbr(nbr);
}
