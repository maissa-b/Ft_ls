/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 06:41:12 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 06:41:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_putnbr_color(char *color, int n)
{
	ft_putstr(color);
	ft_putnbr(n);
	ft_putstr(NONE);
}
