/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtfix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:29:57 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:30:13 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_uncle_colour(t_rbt *root, t_rbt **uncle)
{
	t_rbt *parent;

	parent = root->parent;
	if (parent->parent->left == parent)
		*uncle = parent->parent->right;
	else
		*uncle = parent->parent->left;
	return ((*uncle) ? (*uncle)->colour : BLACK);
}

static void		black_uncle(t_rbt *x, t_rbt *p, t_rbt *g)
{
	if (p == g->left && x == p->left)
	{
		ft_rbtrotate(g, 'r');
		ft_rbtswapcolours(g, p);
	}
	else if (p == g->left && x == p->right)
	{
		ft_rbtrotate(p, 'l');
		ft_rbtrotate(g, 'r');
		ft_rbtswapcolours(x, g);
	}
	else if (p == g->right && x == p->right)
	{
		ft_rbtrotate(g, 'l');
		ft_rbtswapcolours(g, p);
	}
	else
	{
		ft_rbtrotate(p, 'r');
		ft_rbtrotate(g, 'l');
		ft_rbtswapcolours(x, g);
	}
}

static void		red_uncle(t_rbt **current, t_rbt *uncle)
{
	(*current)->parent->colour = BLACK;
	uncle->colour = BLACK;
	(*current)->parent->parent->colour = RED;
	*current = (*current)->parent->parent;
}

void			ft_rbtfix(t_rbt **root_node, t_rbt *new)
{
	t_rbt	*uncle;

	if (ft_rbtisvalid(*root_node))
		return ;
	while (new->parent && new->parent->colour == RED)
	{
		if (get_uncle_colour(new, &uncle) == RED)
			red_uncle(&new, uncle);
		else
		{
			black_uncle(new, new->parent, new->parent->parent);
			break ;
		}
	}
	*root_node = ft_rbtgetroot(new);
	(*root_node)->colour = BLACK;
}
