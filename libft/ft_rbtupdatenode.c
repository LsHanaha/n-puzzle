/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtupdatenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:39:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:39:24 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Updates the contents of *old with contents of *new,
**	does not move *old anywhere in the tree.
**	Deletes *new.
*/

void	ft_rbtupdatenode(t_rbt *old, t_rbt *new)
{
	if (!old || !new)
		return ;
	ft_delcontent(&(old->content), &(old->content_size));
	old->id = new->id;
	old->content = new->content;
	old->content_size = new->content_size;
	free(new);
}
