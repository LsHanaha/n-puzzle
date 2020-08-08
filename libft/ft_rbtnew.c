/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:15 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:16 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbt	*ft_rbtnew(int id, void const *content, size_t size)
{
	t_rbt	*out;

	out = (t_rbt *)malloc(sizeof(t_rbt));
	if (!out)
		return (NULL);
	out->id = id;
	out->parent = NULL;
	out->left = NULL;
	out->right = NULL;
	out->colour = BLACK;
	if (!content || !size)
	{
		out->content = NULL;
		out->content_size = 0;
		return (out);
	}
	out->content_size = size;
	out->content = malloc(size);
	if (!(out->content))
	{
		ft_rbtdel(&out, &ft_delcontent);
		return (NULL);
	}
	ft_memmove(out->content, content, size);
	return (out);
}
