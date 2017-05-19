/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strc_to_stri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 06:47:22 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/13 07:06:21 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*replacebyspace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && !(ft_isdigit(str[i])))
			str[i] = ' ';
		i++;
	}
	return (str);
}

int			*ft_strc_to_stri(char *str)
{
	int		*stock;
	char	**tmp;
	int		i;
	int		j;

	str = replacebyspace(str);
	i = 0;
	j = count_int_in_str(str);
	stock = (int *)malloc(sizeof(int) * j);
	tmp = ft_strsplit(str, ' ');
	while (j > 0)
	{
		stock[i] = ft_atoi(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
		j--;
	}
	return (stock);
}
