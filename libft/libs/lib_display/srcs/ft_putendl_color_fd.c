/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:08:18 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 06:30:59 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putendl_color_fd(char *color, char *str, int fd)
{
	ft_putstr_color_fd(color, str, fd);
	ft_putchar('\n');
}
