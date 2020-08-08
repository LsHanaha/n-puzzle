/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:28:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:28:39 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*f)(t_list *, void *), void *data)
{
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (f(lst, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
