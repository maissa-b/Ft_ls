/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:00:56 by maissa-b          #+#    #+#             */
/*   Updated: 2015/12/23 19:03:59 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char			*ft_free_and_join(char *str1, char *str2)
{
	char		*ret;

	ret = NULL;
	if (str1 && str2)
	{
		ret = ft_strdup(str1);
		ft_strdel(&str1);
		str1 = ft_strjoin(ret, str2);
		ft_strdel(&ret);
	}
	return (str1);
}
