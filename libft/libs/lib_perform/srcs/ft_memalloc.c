/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:29:23 by maissa-b          #+#    #+#             */
/*   Updated: 2015/06/25 08:21:25 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_perform.h>

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (!size || !(a = (void *)malloc(sizeof(void *) * size)))
		return (NULL);
	ft_memset(a, 0, size);
	return (a);
}
