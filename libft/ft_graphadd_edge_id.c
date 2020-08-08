/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_edge_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:19:49 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:22:38 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_edge_id(t_graph *g, uint32_t source, uint32_t sink)
{
	t_list	*value;

	if (source >= g->size || sink >= g->size
			|| g->items[source] == NULL || g->items[sink] == NULL
			|| g->items[source] == DELETED_HI || g->items[sink] == DELETED_HI)
		return ;
	value = g->items[source]->value;
	ft_lstadd(&value, ft_lstnew(&sink, sizeof(uint32_t)));
	g->items[source]->value = value;
}
