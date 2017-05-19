/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:45:17 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:16:34 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

char		*ft_strrchr(const char *str, int i)
{
	const char	*tmp;

	tmp = str + ft_strlen(str);
	while (*tmp != (char)i && tmp != str)
		tmp--;
	if (*tmp == (char)i)
		return ((char *)tmp);
	return (NULL);
}
