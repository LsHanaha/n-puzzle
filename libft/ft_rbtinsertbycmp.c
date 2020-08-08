/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtinsertbycmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:30:31 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:30:36 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	simple_btree_insert_by_cmp(t_rbt *root, t_rbt *new,
		int (*cmp)(void *, void *), enum e_rbt_replace replace)
{
	if (!root || !new || !cmp)
		return ;
	if (cmp(new->content, root->content) < 0)
		if (root->left)
			simple_btree_insert_by_cmp(root->left, new, cmp, replace);
		else
		{
			root->left = new;
			new->parent = root;
		}
	else if (cmp(new->content, root->content) > 0 || replace == RBT_ADD)
		if (root->right)
			simple_btree_insert_by_cmp(root->right, new, cmp, replace);
		else
		{
			root->right = new;
			new->parent = root;
		}
	else
		ft_rbtupdatenode(root, new);
}

void		ft_rbtinsertbycmp(t_rbt **root_node, t_rbt *new,
		int (*cmp)(void *, void *), enum e_rbt_replace replace)
{
	if (!root_node || !new || !cmp)
		return ;
	if (!(*root_node))
	{
		*root_node = new;
		return ;
	}
	new->colour = RED;
	simple_btree_insert_by_cmp(*root_node, new, cmp, replace);
	ft_rbtfix(root_node, new);
}
