/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:30:54 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 15:30:55 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varrdel(t_varr **varr)
{
	if (!varr || !(*varr))
		return ;
	if ((*varr)->buf)
		ft_lstdel(&(*varr)->buf, ft_delcontent);
	free(*varr);
	*varr = NULL;
}
