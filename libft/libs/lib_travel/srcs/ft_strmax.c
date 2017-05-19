/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:55:57 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/18 20:03:46 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int			ft_strmax(char *str1, char *str2)
{
	int		max;
	int		len1;
	int		len2;

	max = 0;
	len1 = 0;
	len2 = 0;
	if (str1 && str2)
	{
		len1 = ft_strlen(str1);
		len2 = ft_strlen(str2);
		max = len1;
		if (len1 < len2)
			max = len2;
	}
	return (max);
}
