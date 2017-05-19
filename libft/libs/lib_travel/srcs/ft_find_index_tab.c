/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 06:35:39 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 10:59:26 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int			ft_find_index_tab(char *search, char **tab, size_t len)
{
	int		i;

	i = 0;
	if (!search || !tab || !len)
		return (-1);
	len = ft_strlen(search);
	while (tab[i])
	{
		if (ft_strnequ(tab[i], search, len))
			return (i);
		i++;
	}
	return (-1);
}
