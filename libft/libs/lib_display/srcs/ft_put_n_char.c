/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_n_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:46:33 by maissa-b          #+#    #+#             */
/*   Updated: 2015/10/25 18:46:34 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_display.h>

void				ft_put_n_char(char character, unsigned int len)
{
	unsigned int	n;

	if (character && len)
	{
		n = len + 1;
		while (--n != 0)
		{
			write(1, &character, 1);
		}
	}
}
