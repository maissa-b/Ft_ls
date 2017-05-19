/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 19:44:44 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/25 19:52:10 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char			*ft_strupper(char *str)
{
	char		*ret;
	int			i;

	i = -1;
	ret = NULL;
	if (str)
	{
		ret = ft_strdup(str);
		while (ret[++i])
		{
			if (ft_islower(ret[i]))
			{
				ret[i] = ft_toupper(ret[i]);
			}
		}
	}
	return (ret);
}
