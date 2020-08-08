/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:43:55 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:46:53 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strfind(const char *s, int c)
{
	size_t	out;

	if (!s)
		return (-1);
	if (!((char)c))
		return ((long)ft_strlen(s));
	out = 0;
	while (s[out])
	{
		if (s[out] == (char)c)
			return ((long)out);
		out++;
	}
	return (-1);
}
