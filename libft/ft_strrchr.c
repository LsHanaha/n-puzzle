/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	if (!(char)c)
		return ((char *)s + ft_strlen(s));
	out = NULL;
	while (*s)
	{
		if (*s == (char)c)
			out = (char *)s;
		s++;
	}
	return (out);
}
