/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilogb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:27:24 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:30:06 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <math.h>

/*
** Little endian only.
*/

int	ft_ilogb(double x)
{
	int		out;
	void	*addr;

	addr = &x;
	if (x == 0)
		return (FP_ILOGB0);
	if (x != x)
		return (FP_ILOGBNAN);
	if (x == INFINITY || x == -INFINITY)
		return (INT_MAX);
	out = ((0x7ff0 & *((unsigned short *)addr + 3)) >> 4) - 0x3ff;
	return (out);
}
