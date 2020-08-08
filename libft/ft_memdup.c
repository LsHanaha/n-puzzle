/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:46:42 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:46:43 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t n)
{
	void	*out;

	if (!s || !n || !(out = malloc(n)))
		return (NULL);
	ft_memcpy(out, s, n);
	return (out);
}
