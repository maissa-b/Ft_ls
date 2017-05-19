/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:47:20 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/10 16:31:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putnbr_fd(int n, int fd)
{
	char	*tmp;

	tmp = ft_itoa(n);
	ft_putstr_fd(tmp, fd);
	ft_strdel(&tmp);
}
