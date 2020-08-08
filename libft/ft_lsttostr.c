/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:42:08 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:42:11 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttostr(t_list *lst, char sep)
{
	t_list	*current;
	size_t	total_len;
	char	*out;

	if (!lst)
		return (NULL);
	current = lst;
	total_len = 0;
	while (current)
	{
		total_len += ft_strlen(current->content) + (sep && current->next);
		current = current->next;
	}
	current = lst;
	out = ft_strnew(total_len);
	if (!out)
		return (NULL);
	while (current)
	{
		out = ft_stpcpy(out, current->content);
		if (sep && current->next)
			*out++ = sep;
		current = current->next;
	}
	return (out - total_len);
}
