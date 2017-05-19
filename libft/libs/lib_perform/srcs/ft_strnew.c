/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:17:32 by maissa-b          #+#    #+#             */
/*   Updated: 2015/08/25 15:32:48 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

char		*ft_strnew(size_t size)
{
	char	*mem;

	mem = (char *)malloc(sizeof(*mem) * (size + 1));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
