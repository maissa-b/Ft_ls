/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 09:36:55 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 09:36:56 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		**ft_tabreplace(char **replaced, char *search, char *replace)
{
	int		i;

	i = 0;
	if (!replaced || !search || !replace)
		return (NULL);
	while (replaced[i])
	{
		if (ft_strnequ(replaced[i], search, ft_strlen(search)))
			replaced[i] = ft_strreplace(replaced[i], search, replace);
		i++;
	}
	return (replaced);
}
