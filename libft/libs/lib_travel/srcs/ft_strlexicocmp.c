/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlexicocmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 20:24:43 by maissa-b          #+#    #+#             */
/*   Updated: 2015/11/25 19:54:34 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int				ft_strlexicocmp(char *str1, char *str2)
{
	int			i;
	int			ret;
	char		*tmp1;
	char		*tmp2;

	i = 0;
	ret = 0;
	if (str1 && str2)
	{
		tmp1 = ft_strlower(str1);
		tmp2 = ft_strlower(str2);
		while (str1[i] && str2[i])
		{
			if ((tmp1[i] - tmp2[i]) != 0)
				break ;
			i++;
		}
		ret = (tmp1[i] - tmp2[i]);
		ft_multifruee(&tmp1, &tmp2, NULL);
	}
	return (ret);
}
