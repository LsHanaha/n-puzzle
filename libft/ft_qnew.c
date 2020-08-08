/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:29:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:29:34 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_qnew(t_list *elem)
{
	t_queue	*out;

	out = (t_queue *)malloc(sizeof(t_queue));
	if (!out)
		return (NULL);
	out->data = elem;
	out->last = elem;
	return (out);
}
