/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtnewlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:15 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:16 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Does not copy content, just assigns the pointer.
*/

t_rbt	*ft_rbtnewlink(int id, void const *content, size_t size)
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
	out->content = content;
	out->content_size = size;
	return (out);
}
