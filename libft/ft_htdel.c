/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:25:04 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:25:05 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_htdel(t_htab **table, void (*delfunc)(t_hash_item **))
{
	uint32_t	i;

	if (!table || !(*table) || !(*table)->items || !delfunc)
		return ;
	i = 0;
	while (i < (*table)->size)
	{
		if ((*table)->items[i] != NULL && (*table)->items[i] != DELETED_HI)
			delfunc(&((*table)->items[i]));
		++i;
	}
	free((*table)->items);
	free(*table);
	*table = NULL;
}
