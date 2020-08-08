/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtgetbheight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:51 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:52 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Always assumes the tree passed is a valid red-black tree
*/

unsigned int	ft_rbtgetbheight(t_rbt *root)
{
	unsigned int	bheight;

	if (!root)
		return (0);
	bheight = (root->colour == BLACK);
	while (root->left)
	{
		bheight += (root->left->colour == BLACK);
		root = root->left;
	}
	return (bheight + 1);
}
