/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;

	if (!s)
		return (NULL);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	return (out);
}
