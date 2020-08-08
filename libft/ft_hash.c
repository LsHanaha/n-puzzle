/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:23:55 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:24:38 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	ft_pow_(uint32_t n, size_t exp)
{
	uint32_t	out;

	out = 1;
	while (exp-- != 0)
		out *= n;
	return (out);
}

uint32_t		ft_hash(void const *key, size_t ksize, uint32_t base,
		uint32_t tabsize)
{
	uint32_t	out;
	size_t		i;

	out = 0;
	i = 0;
	while (i < ksize)
	{
		out += (ft_pow_(base, ksize - (i + 1)) * ((unsigned char *)key)[i]);
		++i;
	}
	return (out % tabsize);
}
