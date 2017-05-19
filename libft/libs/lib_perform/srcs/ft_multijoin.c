/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:36:27 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/15 01:45:09 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_multijoin(char *ret, char *str1, char *str2, char *str3)
{
	char	*tmp;

	if (!str1 || !str2 || !str3)
		return (NULL);
	ret = NULL;
	tmp = ft_strjoin(str1, str2);
	ret = ft_strjoin(tmp, str3);
	ft_strdel(&tmp);
	return (ret);
}
