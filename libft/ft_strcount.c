/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:47:14 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:47:15 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcount(char *s, char c)
{
	unsigned int	count;

	if (!s)
		return (0);
	if (!c)
		return (1);
	count = 0;
	while (*s)
		if (*s++ == c)
			++count;
	return (count);
}
