/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:08:06 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 06:31:09 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putstr_color(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(NONE);
}
