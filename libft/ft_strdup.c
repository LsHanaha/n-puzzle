/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:34 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;

	if (!s)
		return (NULL);
	out = (char *)malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	return (ft_strcpy(out, s));
}
