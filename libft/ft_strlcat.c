/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:40:49 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	destlen = ft_strlen(dest);
	if (destlen > size)
		return (size + srclen);
	i = destlen;
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	if (i < size)
		dest[i] = '\0';
	return (destlen + srclen);
}
