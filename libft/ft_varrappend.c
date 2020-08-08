/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:30:51 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:30:52 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varrappend(t_varr *varr, void const *content)
{
	t_list	*last;
	t_list	*newlst;

	if (!varr || !content)
		return ;
	if (varr->size && varr->size % VARR_BUF_SIZE == 0)
	{
		newlst = ft_lstnewmem(varr->elem_size * VARR_BUF_SIZE);
		if (!newlst)
			exit(1);
		last = ft_lstappend(varr->buf, newlst);
	}
	else
	{
		last = varr->buf;
		while (last->next)
			last = last->next;
	}
	ft_memmove((char *)last->content +
			(varr->elem_size * (varr->size % VARR_BUF_SIZE)),
			content, varr->elem_size);
	++(varr->size);
}
