/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:46:40 by maissa-b          #+#    #+#             */
/*   Updated: 2015/10/25 18:46:42 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void		ft_puts_until(char *str, unsigned int len)
{
	if (str && len)
	{
		if (ft_strlen(str) < len)
			len = ft_strlen(str);
		write(1, str, len);
	}
}
