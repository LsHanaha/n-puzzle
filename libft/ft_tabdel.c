/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:41:00 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 19:41:02 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab)
{
	char **tofree;

	if (!tab)
		return ;
	tofree = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tofree);
}
