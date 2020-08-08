/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:35 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 18:33:40 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	t_list	*lst;
	char	**tab;

	if (!s)
		return (NULL);
	lst = ft_strlsplit(s, c);
	if (!lst)
		return (NULL);
	tab = ft_lsttotab(lst);
	ft_lstdel(&lst, &ft_delcontent);
	if (!tab)
		return (NULL);
	return (tab);
}
