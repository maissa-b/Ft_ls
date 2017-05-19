/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:52:44 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:42 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (d < s)
	{
		while (i < len && s[i])
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (i != len)
		{
			d[len - i - 1] = s[len - i - 1];
			i++;
		}
	}
	return (d);
}
