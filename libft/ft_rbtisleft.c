/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtisleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:04 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:42:53 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	When passed a node without a parent or NULL, will segfault
**	(because what the hell is it supposed to return?)
*/

int	ft_rbtisleft(t_rbt *node)
{
	return (node == node->parent->left);
}
