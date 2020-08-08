/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:43 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

t_regex_match	ft_regex_search(t_fa_state *regex, char *s)
{
	t_regex_match	match;

	if (!s)
		return ((t_regex_match){0, 0});
	match.start = s;
	while (*match.start)
	{
		if ((match.end = ft_regex_pmatch(regex, match.start)))
			return (match);
		match.start++;
	}
	return ((t_regex_match){0, 0});
}
