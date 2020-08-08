/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:30:57 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:30:59 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_varrget(t_varr *varr, size_t idx)
{
	t_list	*current;

	if (!varr || idx >= varr->size)
		exit(1);
	current = varr->buf;
	while (idx >= VARR_BUF_SIZE)
	{
		current = current->next;
		idx -= VARR_BUF_SIZE;
	}
	return ((char *)current->content + (varr->elem_size * idx));
}
