/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:45:34 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:22:18 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (s2 == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
