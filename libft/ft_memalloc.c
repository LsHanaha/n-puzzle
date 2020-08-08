/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:35:03 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(size);
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
		out[i++] = 0;
	return (out);
}
