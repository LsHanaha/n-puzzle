/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:19:32 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:22:03 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_edge(t_graph *g, t_obj *a, t_obj *b)
{
	int64_t	aid;
	int64_t	bid;

	if (!a || !b)
		return ;
	aid = ft_htgetid(g, a->data, a->size);
	if (aid < 0)
		return ;
	bid = ft_htgetid(g, b->data, b->size);
	if (bid < 0)
		return ;
	ft_graphadd_edge_id(g, aid, bid);
}
