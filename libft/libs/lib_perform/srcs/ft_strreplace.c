/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 18:01:53 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:23:33 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strreplace(char *replaced, char *search, char *replace)
{
	char	*res;
	char	*endstr;
	char	*tmp;
	char	*second_tmp;

	if (!replaced || !search || !replace)
		return (NULL);
	else if (ft_strstr(replace, search))
		return (NULL);
	replaced = ft_strdup(replaced);
	while ((res = ft_strstr(replaced, search)))
	{
		tmp = replaced;
		replaced = ft_strsub(replaced, 0, (res - replaced));
		second_tmp = replaced;
		replaced = ft_strjoin(replaced, replace);
		endstr = ft_strdup(res + ft_strlen(search));
		free(tmp);
		tmp = replaced;
		replaced = ft_strjoin(replaced, endstr);
		free(tmp);
		free(endstr);
		free(second_tmp);
	}
	return (replaced);
}
