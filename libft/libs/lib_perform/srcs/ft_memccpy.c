/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:24 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:29 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	const char		*s;
	unsigned char	k;

	k = (char)c;
	d = dst;
	s = src;
	if (n)
	{
		while (n > 0)
		{
			if ((*d++ = *s++) == k)
				return (d);
			--n;
		}
	}
	return (0);
}
