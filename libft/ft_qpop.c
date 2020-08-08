/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:29:36 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:29:37 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_qpop(t_queue *q)
{
	t_list	*out;

	if (!q || !q->data)
		return (NULL);
	out = q->data;
	if (q->last == out)
		q->last = NULL;
	q->data = q->data->next;
	out->next = NULL;
	return (out);
}
