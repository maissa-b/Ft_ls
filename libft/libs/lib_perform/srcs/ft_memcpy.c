/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:02:41 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:33 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*j;
	const char	*k;

	j = (char *)dst;
	k = (const char *)src;
	i = 0;
	while (n--)
	{
		j[i] = k[i];
		i++;
	}
	return (dst);
}
