/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:26:02 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:34:47 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void **, size_t *))
{
	if (!alst || !(*alst) || (!del))
		return ;
	del(&((*alst)->content), &((*alst)->content_size));
	free(*alst);
	*alst = NULL;
}
