/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:42 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

int	ft_regex_match(t_fa_state *regex, char const *s)
{
	if (!s)
		return (0);
	if (!regex || !(regex->next || regex->enext))
		return (1);
	if (*s && regex->cmp && regex->cmp(*s, regex->data))
		return (ft_regex_match(regex->next, s + 1)
				|| (regex->enext ? ft_regex_match(regex->enext, s) : 0));
	else if (regex->enext)
		return (ft_regex_match(regex->enext, s));
	return (0);
}
