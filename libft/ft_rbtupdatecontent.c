/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtupdatecontent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:39:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 13:35:46 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rbtupdatecontent(t_rbt *node, void *content, size_t size)
{
	if (!node || !content || !size)
		return ;
	ft_delcontent(&(node->content), &(node->content_size));
	node->content = ft_memalloc(size);
	if (!(node->content))
		return ;
	node->content_size = size;
	ft_memmove(node->content, content, size);
}
