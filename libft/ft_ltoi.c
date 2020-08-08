/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:25:37 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 16:08:45 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_ltoi(const char *str)
{
	long	out;
	long	temp;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str != '-') - (*str == '-');
	str += (*str == '-' || *str == '+');
	out = 0;
	while (ft_isdigit(*str))
	{
		temp = out;
		out *= 10;
		if (out / 10 != temp)
			return (temp < 0 ? 0 : -1);
		out += (*str - '0') * sign;
		str++;
		if ((sign < 0 && temp < out) || (sign > 0 && temp > out))
			return (temp < 0 ? 0 : -1);
	}
	return (out);
}
