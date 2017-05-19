/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 15:33:38 by maissa-b          #+#    #+#             */
/*   Updated: 2015/09/29 18:20:28 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_cutstr(char *str, char c)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = NULL;
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}
