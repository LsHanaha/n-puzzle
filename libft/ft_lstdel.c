/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 22:48:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void **, size_t *))
{
	t_list	*current;
	t_list	*next;

	if (!alst || !(*alst) || !del)
		return ;
	current = *alst;
	while (current)
	{
		next = current->next;
		del(&(current->content), &(current->content_size));
		free(current);
		current = next;
	}
	*alst = NULL;
}
