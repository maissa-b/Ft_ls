/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:01:17 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 12:17:14 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_strnequ(char const *str1, char const *str2, size_t n)
{
	if (str1 != NULL && str2 != NULL)
		if (ft_strncmp(str1, str2, n) == 0)
			return (1);
	return (0);
}
