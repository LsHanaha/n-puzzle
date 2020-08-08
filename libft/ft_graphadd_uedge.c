/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_uedge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:19:56 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:22:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_uedge(t_graph *g, t_obj *a, t_obj *b)
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
	ft_graphadd_uedge_id(g, aid, bid);
}
