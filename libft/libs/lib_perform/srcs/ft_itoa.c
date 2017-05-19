/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:50:30 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:20 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

static size_t		ft_co_n(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	size_t			len;
	char			*s;
	unsigned int	nb;

	len = ft_co_n(n);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = nb % 10 + '0';
	while (nb /= 10)
		s[--len] = nb % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
