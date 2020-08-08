/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilogbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:27:38 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:30:17 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <math.h>

/*
** Little endian only.
*/

int	ft_ilogbl(long double x)
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
	out = (0x7fff & *((unsigned short *)addr + 4)) - 0x3fff;
	return (out);
}
