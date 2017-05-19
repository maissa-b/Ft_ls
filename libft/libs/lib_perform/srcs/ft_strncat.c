/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:26:01 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:23:16 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = 0;
		while (j < n)
		{
			s1[i++] = s2[j++];
		}
		s1[i] = 0;
	}
	return (s1);
}
