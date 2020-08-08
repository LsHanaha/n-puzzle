/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:37:33 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	size_t	i;

	if (!s || !f)
		return (NULL);
	out = ft_strnew(ft_strlen(s));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(s[i]);
		i++;
	}
	return (out);
}
