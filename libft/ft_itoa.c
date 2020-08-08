/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:32 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:34:27 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_int_len(int n)
{
	int	out;

	out = n <= 0;
	while (n != 0)
	{
		n /= 10;
		out++;
	}
	return (out);
}

char				*ft_itoa(int n)
{
	char			*out;
	unsigned int	len;

	len = get_int_len(n);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	if (n <= 0)
		out[0] = n < 0 ? '-' : '0';
	out[len] = '\0';
	while (n != 0)
	{
		out[len - 1] = n % 10 * ((n > 0) - (n < 0)) + '0';
		n /= 10;
		len--;
	}
	return (out);
}
