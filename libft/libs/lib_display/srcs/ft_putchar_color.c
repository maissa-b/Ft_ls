/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:34:38 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 09:34:39 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_putchar_color(char *color, char c)
{
	ft_putstr(color);
	ft_putchar(c);
	ft_putstr(NONE);
}
