/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:24:46 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:24:47 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hidel(t_hash_item **item)
{
	if (!item || !(*item) || *item == DELETED_HI)
		return ;
	if ((*item)->key)
		free((*item)->key);
	if ((*item)->value)
		free((*item)->value);
	free(*item);
	*item = DELETED_HI;
}
