/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtinsertbyid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:00 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:02 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		simple_btree_insert_by_id(t_rbt *root, t_rbt *new)
{
	if (!root || !new)
		return ;
	if (new->id < root->id)
		if (root->left)
			simple_btree_insert_by_id(root->left, new);
		else
		{
			root->left = new;
			new->parent = root;
		}
	else if (new->id > root->id)
		if (root->right)
			simple_btree_insert_by_id(root->right, new);
		else
		{
			root->right = new;
			new->parent = root;
		}
	else
		ft_rbtupdatenode(root, new);
}

void			ft_rbtinsertbyid(t_rbt **root_node, t_rbt *new)
{
	if (!root_node || !new)
		return ;
	if (!(*root_node))
	{
		*root_node = new;
		return ;
	}
	new->colour = RED;
	simple_btree_insert_by_id(*root_node, new);
	ft_rbtfix(root_node, new);
}
