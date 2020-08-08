/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 22:53:52 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_next_len(char const **s, char c)
{
	char	*next;
	size_t	len;

	while (**s && **s == c)
		(*s)++;
	next = ft_strchr(*s, c);
	len = next ? (size_t)(next - *s) : ft_strlen(*s);
	return (len);
}

static int		initialize_data
	(t_list **data, t_list **current, char const *s, size_t len)
{
	*data = ft_lstfromchr(s, len);
	*current = *data;
	return (0);
}

t_list			*ft_strlsplit(char const *s, char c)
{
	size_t	len;
	t_list	*data;
	t_list	*current;

	if (!s)
		return (NULL);
	data = NULL;
	while (*s)
	{
		if (!(len = get_next_len(&s, c)))
			break ;
		if (data || initialize_data(&data, &current, s, len))
		{
			current->next = ft_lstfromchr(s, len);
			current = current->next;
		}
		if (!current)
		{
			ft_lstdel(&data, &ft_delcontent);
			return (NULL);
		}
		s += len;
	}
	return (data ? data : ft_lstnew(NULL, 0));
}
