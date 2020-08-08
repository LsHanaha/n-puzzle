/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:29:40 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:29:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qpush(t_queue *q, t_list *elem)
{
	if (!q || !elem)
		return ;
	if (!q->last)
	{
		ft_lstadd(&q->data, elem);
		q->last = q->data;
	}
	else
		q->last = ft_lstappend(q->last, elem);
}
