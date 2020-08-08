/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindnot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:25:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:25:13 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strfindnot(const char *s, int c)
{
	size_t	out;

	if (!s)
		return (-1);
	if (!((char)c))
		return (-1);
	out = 0;
	while (s[out])
	{
		if (s[out] != (char)c)
			return ((long)out);
		out++;
	}
	return (-1);
}
