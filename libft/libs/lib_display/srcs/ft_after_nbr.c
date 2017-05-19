/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:20:46 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/11 20:20:47 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_after_nbr(char c, int len, int nbr)
{
	ft_putnbr(nbr);
	if (len != 0)
		ft_put_n_char(c, len);
}
