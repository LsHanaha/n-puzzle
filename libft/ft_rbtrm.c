/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:18 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:41:28 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		replace_node(t_rbt *node, t_rbt *new_link)
{
	if (!node || !(node->parent))
		return ;
	if (node->parent->left == node)
		node->parent->left = new_link;
	else
		node->parent->right = new_link;
	if (new_link)
		new_link->parent = node->parent;
}

static t_rbt	*find_u(t_rbt **vptr, void (*del)(void **, size_t *))
{
	t_rbt	*v;

	v = *vptr;
	if (v->left && v->right)
	{
		*vptr = ft_rbtmin(v->right);
		del(&(v->content), &(v->content_size));
		v->content = (*vptr)->content;
		v->content_size = (*vptr)->content_size;
		v->id = (*vptr)->id;
		v = *vptr;
		v->content = NULL;
		v->content_size = 0;
	}
	if (!(v->right))
		return (v->left);
	return (v->right);
}

static void		do_rotations(t_rbt *p, t_rbt *s)
{
	if (ft_rbtisleft(s) && ft_rbtcolour(s->left) == RED)
	{
		s->left->colour = s->colour;
		s->colour = p->colour;
		ft_rbtrotate(p, 'r');
	}
	else if (ft_rbtisleft(s) && ft_rbtcolour(s->right) == RED)
	{
		s->right->colour = p->colour;
		ft_rbtrotate(s, 'l');
		ft_rbtrotate(p, 'r');
	}
	else if (!ft_rbtisleft(s) && ft_rbtcolour(s->right) == RED)
	{
		s->right->colour = s->colour;
		s->colour = p->colour;
		ft_rbtrotate(p, 'l');
	}
	else if (!ft_rbtisleft(s) && ft_rbtcolour(s->left) == RED)
	{
		s->left->colour = p->colour;
		ft_rbtrotate(s, 'r');
		ft_rbtrotate(p, 'l');
	}
	p->colour = BLACK;
}

static void		fix_blackblack(t_rbt *u, t_rbt *sibling)
{
	if (!u || !(u->parent))
		return ;
	if (!sibling)
		return (fix_blackblack(u->parent, ft_rbtgetsibling(u->parent)));
	else if (sibling->colour == BLACK && (ft_rbtcolour(sibling->left) == RED ||
			ft_rbtcolour(sibling->right) == RED))
		return (do_rotations(sibling->parent, sibling));
	else if (sibling->colour == BLACK && ft_rbtcolour(sibling->left) == BLACK &&
			ft_rbtcolour(sibling->right) == BLACK)
	{
		sibling->colour = RED;
		if (u->parent->colour == RED)
		{
			u->parent->colour = BLACK;
			return ;
		}
		return (fix_blackblack(u->parent, ft_rbtgetsibling(u->parent)));
	}
	else if (sibling->colour == RED)
	{
		sibling->parent->colour = RED;
		ft_rbtrotate(u->parent, ft_rbtisleft(sibling) ? 'r' : 'l');
		sibling->colour = BLACK;
		fix_blackblack(u, ft_rbtgetsibling(u));
	}
}

void			ft_rbtrm(t_rbt **root, t_rbt *v, void (*del)(void **, size_t *))
{
	t_rbt	*u;

	if (!root || !(*root) || !del || ft_rbtgetroot(v) != *root)
		return ;
	u = find_u(&v, del);
	if (ft_rbtcolour(v) == RED || ft_rbtcolour(u) == RED)
	{
		replace_node(v, u);
		if (u)
			u->colour = BLACK;
	}
	else
	{
		if (!u)
			u = v;
		else
			replace_node(v, u);
		fix_blackblack(u, ft_rbtgetsibling(u));
	}
	*root = ft_rbtgetroot(v->parent);
	if (u == v)
		replace_node(v, NULL);
	ft_rbtdelone(v, del);
}
