/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 18:47:06 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	out = f(lst);
	if (!out)
		return (NULL);
	current = out;
	lst = lst->next;
	while (lst)
	{
		current->next = f(lst);
		if (!(current->next))
		{
			ft_lstdel(&out, &ft_delcontent);
			return (NULL);
		}
		lst = lst->next;
		current = current->next;
	}
	return (out);
}
