/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:41:19 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:13:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int			ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (!n)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)(str1) - *(unsigned char *)(str2));
		if (!*str1 || !*str2)
			return (0);
		str1++;
		str2++;
	}
	return (0);
}
