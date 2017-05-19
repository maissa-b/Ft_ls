/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:34:46 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 09:34:47 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putchar_color_fd(char *color, char c, int fd)
{
	ft_putstr(color);
	ft_putchar_fd(c, fd);
	ft_putstr(NONE);
}
