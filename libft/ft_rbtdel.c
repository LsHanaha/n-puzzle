/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:36 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rbtdel(t_rbt **tree, void (*del)(void **, size_t *))
{
	if (!tree || !(*tree))
		return ;
	if ((*tree)->left)
		ft_rbtdel(&((*tree)->left), del);
	if ((*tree)->right)
		ft_rbtdel(&((*tree)->right), del);
	ft_rbtdelone(*tree, del);
	*tree = NULL;
}
