/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtswapcolours.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:29 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:33 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rbtswapcolours(t_rbt *a, t_rbt *b)
{
	int	temp;

	if (!a || !b || a->colour == b->colour)
		return ;
	temp = a->colour;
	a->colour = b->colour;
	b->colour = temp;
}
