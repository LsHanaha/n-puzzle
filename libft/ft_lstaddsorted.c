/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:26:46 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:28:20 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsorted
	(t_list **alst, t_list *newlst, int (*cmp)(void *, void *))
{
	t_list *current;

	if (!alst || !newlst || !cmp)
		return ;
	if (!(*alst))
	{
		*alst = newlst;
		return ;
	}
	current = *alst;
	if (cmp(newlst->content, current->content) <= 0)
	{
		newlst->next = current;
		*alst = newlst;
		return ;
	}
	while (current->next && cmp(newlst->content, current->next->content) > 0)
		current = current->next;
	newlst->next = current->next;
	current->next = newlst;
}
