/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:20:35 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/11 20:20:36 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_before_str(char c, int len, char *str)
{
	if (str && c)
	{
		if (len != 0)
			ft_put_n_char(c, len);
		ft_putstr(str);
	}
}
