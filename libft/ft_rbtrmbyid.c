/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtrmbyid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:22 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:23 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rbtrmbyid(t_rbt **root, int id,
		void (*del)(void **, size_t *))
{
	t_rbt				*v;

	if (!root || !(*root) || !del || !((v = ft_rbtfindbyid(*root, id))))
		return ;
	ft_rbtrm(root, v, del);
}
