/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:53:06 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:16:56 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

char				*ft_strstr(const char *str1, const char *str2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(str2);
	if (j == '\0')
		return ((char *)str1);
	else if (ft_strlen(str1) < j)
		return (NULL);
	while (str1[i + j - 1])
	{
		if (ft_memcmp(str1 + i, str2, j) == 0)
			return ((char *)str1 + i);
		i++;
	}
	return (NULL);
}
