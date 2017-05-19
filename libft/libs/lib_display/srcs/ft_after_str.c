/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:20:26 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/11 20:20:28 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void			ft_after_str(char c, int len, char *str)
{
	if (str && c)
	{
		ft_putstr(str);
		if (len != 0)
			ft_put_n_char(c, len);
	}
}
