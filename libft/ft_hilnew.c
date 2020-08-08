/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hilnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:24:53 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:26:11 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_item	*ft_hilnew
	(void const *key, size_t ksize, void *value, size_t vsize)
{
	t_hash_item	*out;

	if (!key || !ksize)
		return (NULL);
	out = (t_hash_item *)malloc(sizeof(t_hash_item));
	if (!out)
		return (NULL);
	out->key = malloc(ksize);
	if (!out->key)
	{
		free(out);
		return (NULL);
	}
	ft_memmove(out->key, key, ksize);
	out->ksize = ksize;
	out->value = value;
	out->vsize = vsize;
	return (out);
}
