/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 18:47:26 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	if (!content || !size)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		out->content = malloc(size);
		if (!(out->content))
		{
			ft_lstdel(&out, &ft_delcontent);
			return (NULL);
		}
		ft_memmove(out->content, content, size);
		out->content_size = size;
	}
	out->next = NULL;
	return (out);
}
