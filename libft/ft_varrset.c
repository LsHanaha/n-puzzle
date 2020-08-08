/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:31:04 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:31:26 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Currently only assigning to values that already exist in the array
**	is supported.
*/

void	ft_varrset(t_varr *varr, size_t idx, void *content)
{
	t_list	*current;

	if (!varr || !content || idx >= varr->size)
		exit(1);
	current = varr->buf;
	while (idx >= VARR_BUF_SIZE)
	{
		current = current->next;
		idx -= VARR_BUF_SIZE;
	}
	ft_memmove((char *)current->content + (varr->elem_size * idx),
			content, varr->elem_size);
}
