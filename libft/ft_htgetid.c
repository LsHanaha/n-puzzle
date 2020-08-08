/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htgetid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:25:16 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:25:16 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_htgetid(t_htab *table, void const *key, size_t ksize)
{
	t_hash_collision_info	info;
	uint32_t				hash;

	if (!table || !table->items || !key || !ksize)
		return (-1);
	info.base = table->base;
	info.altbase = table->altbase;
	info.attempt = 0;
	while (1)
	{
		hash = ft_hashget(key, ksize, &info, table->size);
		if (table->items[hash] == NULL)
			return (-1);
		if (table->items[hash] != DELETED_HI
				&& table->items[hash]->ksize == ksize
				&& !ft_memcmp(table->items[hash]->key, key, ksize))
			return (hash);
		++info.attempt;
	}
}
