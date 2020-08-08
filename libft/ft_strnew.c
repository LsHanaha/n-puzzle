/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 16:14:10 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;
	size_t	i;

	if (!(size + 1))
		return (NULL);
	out = (char *)malloc(size + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i <= size)
		out[i++] = '\0';
	return (out);
}
