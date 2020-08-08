/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtgetroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:54 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:55 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbt	*ft_rbtgetroot(t_rbt *node)
{
	if (!node)
		return (NULL);
	while (node->parent)
		node = node->parent;
	return (node);
}
