/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 22:09:01 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:24:25 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

static unsigned int		ft_stat_trim(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char					*ft_strtrim(char const *s)
{
	char				*s_m;
	size_t				i;
	size_t				j;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_stat_trim(*s++))
		i++;
	s -= i + 1;
	j = ft_strlen(s) - 1;
	if (i != (j + 1))
	{
		while (ft_stat_trim(s[j]))
			j--;
	}
	s_m = ft_strsub(s, i, (j - i + 1));
	return (s_m);
}
