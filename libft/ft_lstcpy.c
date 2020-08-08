/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:19:37 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/29 21:21:25 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*out;
	t_list	*current;

	if (!lst)
		return (NULL);
	out = ft_lstnew(lst->content, lst->content_size);
	if (!out)
		return (NULL);
	current = out;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(lst->content, lst->content_size);
		if (!current->next)
		{
			ft_lstdel(&out, &ft_delcontent);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (out);
}
