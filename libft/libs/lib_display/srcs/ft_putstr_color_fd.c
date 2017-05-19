/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:05:02 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 06:31:08 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putstr_color_fd(char *color, char *str, int fd)
{
	ft_putstr(color);
	ft_putstr_fd(str, fd);
	ft_putstr(NONE);
}
