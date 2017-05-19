/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:33:05 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:24:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*t;
	size_t		l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len > l || start > l)
		return (NULL);
	if (!(t = ft_strnew(len)))
		return (NULL);
	else
	{
		t = ft_strncpy(t, s + start, len);
		t[len] = '\0';
		return (t);
	}
}
