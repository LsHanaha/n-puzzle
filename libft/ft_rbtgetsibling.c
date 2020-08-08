/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtgetsibling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:57 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:58 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbt	*ft_rbtgetsibling(t_rbt *node)
{
	if (!node || !(node->parent))
		return (NULL);
	else
		return (node->parent->left == node ?
				node->parent->right : node->parent->left);
}
