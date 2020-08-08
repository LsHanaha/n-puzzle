/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:25:08 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:25:10 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strfindif(const char *s, int (*f)(char))
{
	size_t	out;

	if (!s)
		return (-1);
	out = 0;
	while (s[out])
	{
		if (f(s[out]))
			return ((long)out);
		out++;
	}
	return (-1);
}
