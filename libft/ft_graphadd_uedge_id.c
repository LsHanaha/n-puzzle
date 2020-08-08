/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_uedge_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:20:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:22:49 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_uedge_id(t_graph *g, uint32_t a, uint32_t b)
{
	ft_graphadd_edge_id(g, a, b);
	ft_graphadd_edge_id(g, b, a);
}
