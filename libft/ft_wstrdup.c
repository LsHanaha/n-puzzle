/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:23:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:23:36 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	u32to8strlen(wchar_t *s)
{
	size_t	out;

	if (!s)
		return (0);
	out = 0;
	while (*s)
	{
		if (*s < 0x80)
			out += 1;
		else if (*s < 0x800)
			out += 2;
		else if (*s < 0x10000)
			out += 3;
		else
			out += 4;
		++s;
	}
	return (out);
}

char			*ft_wstrdup(wchar_t *s)
{
	char	*out;
	int		i;

	if (!s)
		return (NULL);
	out = ft_strnew(u32to8strlen(s));
	if (!out)
		return (NULL);
	i = 0;
	while (*s)
	{
		i += ft_u32to8(*s, out + i);
		++s;
	}
	return (out);
}
