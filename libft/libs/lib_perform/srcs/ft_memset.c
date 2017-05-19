/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:32:18 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:45 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*j;

	j = (unsigned char *)b;
	if (len)
	{
		while (len--)
			*j++ = c;
	}
	return (b);
}
