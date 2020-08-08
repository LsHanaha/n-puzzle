/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:26 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:43:45 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rotate_left(t_rbt *x, t_rbt **yptr)
{
	t_rbt	*y;

	y = x->right;
	x->right = y->left;
	if (x->right)
		x->right->parent = x;
	y->left = x;
	*yptr = y;
}

static void	rotate_right(t_rbt *x, t_rbt **yptr)
{
	t_rbt	*y;

	y = x->left;
	x->left = y->right;
	if (x->left)
		x->left->parent = x;
	y->right = x;
	*yptr = y;
}

/*
**	Returns the pointer to what is the root (sub-root) now.
*/

t_rbt		*ft_rbtrotate(t_rbt *x, char dir)
{
	t_rbt	*y;

	if (!x || !(dir == 'l' || dir == 'r'))
		return (NULL);
	if (dir == 'l')
		rotate_left(x, &y);
	else
		rotate_right(x, &y);
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->parent = x->parent;
	x->parent = y;
	return (y);
}
