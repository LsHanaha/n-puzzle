/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtfromchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:37:47 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:37:48 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbt	*ft_rbtfromchr(int id, char const *content, size_t len)
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
	if (!content || !len || !(len + 1))
	{
		out->content = NULL;
		out->content_size = 0;
		return (out);
	}
	out->content_size = len + 1;
	out->content = ft_strnew(len);
	if (!(out->content))
	{
		ft_rbtdel(&out, &ft_delcontent);
		return (NULL);
	}
	ft_strncpy(out->content, content, len);
	return (out);
}
