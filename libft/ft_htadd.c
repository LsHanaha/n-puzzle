/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:25:00 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:27:53 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_htadd(t_htab *table, t_hash_item *item)
{
	t_hash_collision_info	info;
	uint32_t				hash;

	if (!table || !table->items || table->count >= table->size
			|| !item || item == DELETED_HI)
		return (-1);
	info.base = table->base;
	info.altbase = table->altbase;
	info.attempt = 0;
	while (table->items[(hash =
			ft_hashget(item->key, item->ksize, &info, table->size))] != NULL
			&& table->items[hash] != DELETED_HI)
		++(info.attempt);
	table->items[hash] = item;
	++(table->count);
	return (hash);
}
