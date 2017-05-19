/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:55:12 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:14:52 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

char		*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	if (!*str2)
		return ((char*)str1);
	while (*str1 && ft_strlen(str2) <= n--)
	{
		if (!ft_memcmp(str1++, str2, ft_strlen(str2)))
			return ((char*)str1 - 1);
	}
	return (NULL);
}
