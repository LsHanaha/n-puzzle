/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_pmatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:43 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

char	*ft_regex_pmatch(t_fa_state *regex, char *s)
{
	char	*match_end;

	if (!s)
		return (NULL);
	if (!regex || !(regex->next || regex->enext))
		return (s);
	if (*s && regex->cmp && regex->cmp(*s, regex->data))
	{
		if ((match_end = ft_regex_pmatch(regex->next, s + 1)))
			return (match_end);
		return (regex->enext ? ft_regex_pmatch(regex->enext, s) : NULL);
	}
	else if (regex->enext)
		return (ft_regex_pmatch(regex->enext, s));
	return (NULL);
}
