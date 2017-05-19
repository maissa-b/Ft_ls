/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:08:48 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:07:44 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

void				*ft_memchr(const void *str1, int i, size_t n)
{
	size_t			j;
	unsigned char	*str2;

	j = 0;
	str2 = (unsigned char *)str1;
	while (j < n)
	{
		if (str2[j] == (unsigned char)i)
			return ((void *)(str2 + j));
		j++;
	}
	return (NULL);
}
