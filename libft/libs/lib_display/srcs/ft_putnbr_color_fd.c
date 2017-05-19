/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 06:41:42 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 06:41:44 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_putnbr_color_fd(char *color, int n, int fd)
{
	ft_putstr(color);
	ft_putnbr_fd(n, fd);
	ft_putstr(NONE);
}
