/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:12:50 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:11:50 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int						ft_strcmp(const char *str1, const char *str2)
{
	int					i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	tmp1 = (const unsigned char *)str1;
	tmp2 = (const unsigned char *)str2;
	i = 0;
	if (!tmp1 || !tmp2)
		return (0);
	while (tmp1[i] && tmp2[i] && tmp1[i] - tmp2[i] == 0)
		i++;
	return (tmp1[i] - tmp2[i]);
}
