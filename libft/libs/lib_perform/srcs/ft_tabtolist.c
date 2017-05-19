/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:31:53 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:24:58 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

t_list		ft_tabtolist(char **tab)
{
	t_list	*list;
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_new_link(list, tab[i]);
		i++;
	}
	return (list);
}
