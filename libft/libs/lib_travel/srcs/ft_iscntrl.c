/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 00:42:31 by maissa-b          #+#    #+#             */
/*   Updated: 2015/07/25 05:48:13 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_travel.h>

int		ft_iscntrl(int c)
{
	return (((c >= 000 && c <= 037) || c == 177) ? 1 : 0);
}
