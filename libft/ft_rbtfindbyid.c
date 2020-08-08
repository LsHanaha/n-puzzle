/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtfindbyid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:41 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:42:33 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the node found by prefix traversal
*/

t_rbt	*ft_rbtfindbyid(t_rbt *root, int id)
{
	if (!root)
		return (NULL);
	if (root->id == id)
		return (root);
	else
		return (id < root->id ? ft_rbtfindbyid(root->left, id) :
		ft_rbtfindbyid(root->right, id));
}
