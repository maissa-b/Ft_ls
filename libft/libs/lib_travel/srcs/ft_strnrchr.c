/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:18:02 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/23 15:35:39 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

char			*ft_strnrchr(char *str, int pos, int n)
{
	int			i;

	i = ft_strlen(str);
	while (i > 0 && n > 0)
	{
		if (str[i] == pos)
			n--;
		if (n == 0)
			break ;
		i--;
	}
	return (&(str[i]));
}
