/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:32 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/05 13:15:12 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the pointer to the newly inserted node;
*/

t_list	*ft_lstappend(t_list *alst, t_list *new)
{
	if (!alst || !new)
		return (NULL);
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	return (new);
}
