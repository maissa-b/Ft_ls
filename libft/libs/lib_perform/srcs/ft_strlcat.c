/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 22:20:21 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:22:56 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

static void		ft_stat_lcat(const char *s, char *d, int esp)
{
	while (*s)
	{
		if (esp != 1)
		{
			*d = *s;
			d++;
			esp--;
		}
		s++;
	}
	*d = '\0';
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len_d;
	size_t		esp;

	d = dst;
	s = src;
	esp = size;
	while (esp && *d)
	{
		d++;
		esp--;
	}
	len_d = d - dst;
	esp = size - len_d;
	if (!esp)
		return (len_d + ft_strlen(src));
	ft_stat_lcat(s, d, esp);
	return (len_d + ft_strlen(src));
}
