/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:38 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:39 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rbtdelone(t_rbt *node, void (*del)(void **, size_t *size))
{
	if (!node)
		return ;
	del(&(node->content), &(node->content_size));
	free(node);
}
