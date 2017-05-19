/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:51:07 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:12:40 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_strequ(char const *str1, char const *str2)
{
	const char *tmp1;
	const char *tmp2;

	if (!str1 || !str2)
		return (0);
	tmp1 = (const char *)str1;
	tmp2 = (const char *)str2;
	if (ft_strcmp(tmp1, tmp2) == 0)
		return (1);
	else
		return (0);
}
