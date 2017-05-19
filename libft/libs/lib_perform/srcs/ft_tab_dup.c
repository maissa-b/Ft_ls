/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 08:43:49 by maissa-b          #+#    #+#             */
/*   Updated: 2015/10/01 18:52:43 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		**ft_tab_dup(char **tab)
{
	int		i;
	char	**tab_dup;

	if (tab == NULL)
		return (NULL);
	i = 0;
	tab_dup = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (tab[i])
	{
		tab_dup[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_dup[i] = NULL;
	return (tab_dup);
}
