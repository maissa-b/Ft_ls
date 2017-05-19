/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:23:05 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:22:49 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*ret;
	size_t		len_1;
	size_t		len_2;

	if (!s1 && s2)
		return (ft_strdup((char*)s2));
	else if (!s2 && s1)
		return (ft_strdup((char*)s1));
	if (s1 != NULL && s2 != NULL)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		if (!(s3 = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1))))
			return (0);
		ret = s3;
		while (*s1)
			*s3++ = *s1++;
		while (*s2)
			*s3++ = *s2++;
		*s3 = '\0';
		return (ret);
	}
	return (NULL);
}
