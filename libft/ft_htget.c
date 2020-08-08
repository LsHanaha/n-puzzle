/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:25:11 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:25:12 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_htget(t_htab *table, void const *key, size_t ksize,
		size_t *vsize)
{
	int64_t	id;

	id = ft_htgetid(table, key, ksize);
	if (id < 0)
		return (NULL);
	if (vsize)
		*vsize = table->items[id]->vsize;
	return (table->items[id]->value);
}
