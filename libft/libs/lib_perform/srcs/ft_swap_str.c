/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:26:34 by maissa-b          #+#    #+#             */
/*   Updated: 2015/10/25 18:26:36 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void		ft_swap_str(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
