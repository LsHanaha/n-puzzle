/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:25:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:26:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_htdel_item(t_htab *table, void *key, size_t ksize,
	void (*delfunc)(t_hash_item **))
{
	int64_t	id;

	if (!delfunc)
		return ;
	id = ft_htgetid(table, key, ksize);
	if (id < 0)
		return ;
	delfunc(&table->items[id]);
}
