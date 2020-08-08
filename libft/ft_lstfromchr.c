/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 22:45:25 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfromchr(char const *content, size_t len)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	if (!content || !len || !(len + 1))
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		out->content = ft_strnew(len);
		if (!(out->content))
		{
			ft_lstdel(&out, &ft_delcontent);
			return (NULL);
		}
		ft_strncpy(out->content, content, len);
		out->content_size = len + 1;
	}
	out->next = NULL;
	return (out);
}
