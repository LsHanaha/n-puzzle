/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:14:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:15:58 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewlink(void *content, size_t size)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->content = content;
	out->content_size = size;
	out->next = NULL;
	return (out);
}
