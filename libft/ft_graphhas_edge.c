/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphhas_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:20:49 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:23:03 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_graphhas_edge(t_graph *g, uint32_t source, uint32_t sink)
{
	t_list	*current;

	if (!g || source >= g->size || sink >= g->size
			|| g->items[source] == NULL || g->items[source] == DELETED_HI
			|| g->items[sink] == NULL || g->items[sink] == DELETED_HI)
		return (0);
	current = g->items[source]->value;
	while (current)
	{
		if (*(uint32_t *)current->content == sink)
			return (1);
		current = current->next;
	}
	return (0);
}
