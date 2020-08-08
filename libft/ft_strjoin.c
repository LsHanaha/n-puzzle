/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 20:08:24 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	out = ft_strnew(s1_len + ft_strlen(s2));
	if (!out)
		return (NULL);
	ft_strcpy(out, s1);
	ft_strcpy(out + s1_len, s2);
	return (out);
}
