/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:35:16 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 04:52:20 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_charreplace(char *replaced, char search, char replace)
{
	int		i;

	i = 0;
	if (!replaced || !replace || !search)
		return (NULL);
	else if (search == replace)
		return (NULL);
	while (replaced[i])
	{
		if (replaced[i] == search)
			replaced[i] = replace;
		i++;
	}
	return (replaced);
}
