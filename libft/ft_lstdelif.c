/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:28:48 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:28:50 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **alst, int (*f)(t_list *, void *),
		void *data, void (*del)(void **, size_t *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!alst || !(*alst) || !f || !del)
		return ;
	prev = NULL;
	current = *alst;
	while (current)
	{
		next = current->next;
		if (f(current, data))
		{
			ft_lstdelone(&current, del);
			if (!prev)
				*alst = next;
			else
				prev->next = next;
		}
		else
			prev = current;
		current = next;
	}
}
