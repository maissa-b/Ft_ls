/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 20:17:39 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/25 19:51:47 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char			*ft_strlower(char *str)
{
	char		*ret;
	int			i;

	ret = NULL;
	i = -1;
	if (str)
	{
		ret = ft_strdup(str);
		while (ret[++i])
		{
			if (ft_isupper(ret[i]))
			{
				ret[i] = ft_tolower(str[i]);
			}
		}
	}
	return (ret);
}
