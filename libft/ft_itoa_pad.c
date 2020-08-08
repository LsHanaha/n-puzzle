/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:25:24 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:25:26 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n)
{
	int	out;

	out = (n == 0);
	while (n != 0)
	{
		n /= 10;
		out++;
	}
	return (out);
}

char		*ft_itoa_pad(int n, int min_len)
{
	char	*out;
	int		len;

	len = get_int_len(n);
	len = (min_len > len ? min_len : len) + (n < 0);
	out = ft_strnew(len);
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
	while (len > (out[0] ? 1 : 0))
		out[(len--) - 1] = '0';
	return (out);
}
