/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:47:36 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:47:37 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varrcpy(void *dest, t_varr *varr)
{
	size_t	i;

	if (!dest || !varr || !varr->size)
		return ;
	i = 0;
	while (i < varr->size)
	{
		ft_memcpy(dest + i * varr->elem_size,
				ft_varrget(varr, i), varr->elem_size);
		++i;
	}
}
