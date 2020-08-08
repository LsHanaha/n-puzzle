/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtisvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:09 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:43:20 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_bheight(t_rbt *leaf_node)
{
	unsigned int	bheight;

	if (!leaf_node)
		return (0);
	bheight = (leaf_node->colour == BLACK);
	while (leaf_node->parent)
	{
		bheight += (leaf_node->parent->colour == BLACK);
		leaf_node = leaf_node->parent;
	}
	return (bheight + 1);
}

static int			check_tree(t_rbt *node, unsigned int bheight)
{
	if (!node)
		return (1);
	if ((node->parent && node->colour == RED && node->parent->colour == RED) ||
		((!(node->left) || !(node->right)) && get_bheight(node) != bheight))
		return (0);
	return (check_tree(node->left, bheight) &&
		check_tree(node->right, bheight));
}

int					ft_rbtisvalid(t_rbt *root)
{
	if (!root)
		return (0);
	return (check_tree(root, ft_rbtgetbheight(root)));
}
