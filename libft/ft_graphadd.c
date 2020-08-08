/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:19:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:22:30 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_graphadd(t_graph *g, void const *key, size_t ksize)
{
	return (ft_htadd(g, ft_hilnew(key, ksize, NULL, sizeof(t_list))));
}
