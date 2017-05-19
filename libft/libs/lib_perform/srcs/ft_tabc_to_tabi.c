/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabc_to_tabi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 06:56:45 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/13 07:03:05 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

int			**ft_tabc_to_tabi(char **tabc)
{
	int		i;
	int		**tabi;

	i = 0;
	tabi = (int **)malloc(sizeof(int *) * ft_tablen(tabc));
	while (tabc[i])
	{
		tabi[i] = ft_strc_to_stri(tabc[i]);
		i++;
	}
	return (tabi);
}
