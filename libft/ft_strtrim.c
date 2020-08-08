/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:42:23 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspace_custom(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;

	if (!s)
		return (NULL);
	while (isspace_custom(*s))
		s++;
	i = 0;
	len = 0;
	while (s[i])
	{
		if (!isspace_custom(s[i]))
			len = i + 1;
		i++;
	}
	return (ft_strsub(s, 0, len));
}
