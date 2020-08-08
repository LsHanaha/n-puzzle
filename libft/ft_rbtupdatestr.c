/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtupdatestr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:39:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 14:20:34 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Save if memory overlaps.
*/

void	ft_rbtupdatestr(t_rbt *node, char *s, size_t len)
{
	void	*old_content;

	if (!node || !s || !(len + 1))
		return ;
	if (!len)
	{
		ft_delcontent(&(node->content), &(node->content_size));
		node->content = NULL;
		node->content_size = 0;
		return ;
	}
	old_content = node->content;
	node->content = ft_strnew(len);
	if (!(node->content))
		return ;
	ft_strncpy(node->content, s, len);
	ft_delcontent(&(old_content), &(node->content_size));
	node->content_size = len + 1;
}
