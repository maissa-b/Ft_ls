/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multifruee.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:05:18 by maissa-b          #+#    #+#             */
/*   Updated: 2015/09/23 22:11:36 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void		ft_multifruee(char **str1, char **str2, char **str3)
{
	if (*str1 == NULL && *str2 == NULL && *str3 == NULL)
		return ;
	if (str1)
		ft_strdel(str1);
	if (str2)
		ft_strdel(str2);
	if (str3)
		ft_strdel(str3);
}
