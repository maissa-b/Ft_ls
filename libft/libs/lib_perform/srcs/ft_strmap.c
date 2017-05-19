/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:09:24 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:23:03 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*nw;
	int		i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		nw = ft_strnew(len + 1);
		i = 0;
		while (s[i])
		{
			nw[i] = f(s[i]);
			i++;
		}
		return (nw);
	}
	return (NULL);
}
