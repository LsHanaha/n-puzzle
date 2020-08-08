/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hildel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:24:49 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:24:51 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hildel(t_hash_item **item)
{
	if (!item || !(*item) || *item == DELETED_HI)
		return ;
	if ((*item)->key)
		free((*item)->key);
	free(*item);
	*item = DELETED_HI;
}
