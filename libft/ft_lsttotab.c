/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:33 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 22:45:58 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttotab(t_list *lst)
{
	char	**out;
	size_t	i;
	size_t	len;

	if (!lst)
		return (NULL);
	len = lst->content ? ft_lstlen(lst) : 0;
	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = (char *)malloc(lst->content_size);
		if (!(out[i]))
		{
			ft_tabdel(out);
			return (NULL);
		}
		ft_strcpy(out[i], lst->content);
		i++;
		lst = lst->next;
	}
	out[i] = NULL;
	return (out);
}
