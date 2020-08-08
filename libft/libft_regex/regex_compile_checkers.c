/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_compile_checkers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:43 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

long		check_range(char const *p, size_t len)
{
	if (p[len - 1] != ']' || !(len - 1))
		return (-1);
	while (--len > 0)
	{
		if (p[len - 1] == '[')
			return (len - 1);
	}
	return (-1);
}

static int	has_esc_slash(char const *p, size_t len)
{
	return (p[len - 1] == '\\' && (!(len - 1) || !has_esc_slash(p, len - 1)));
}

long		check_special_sequences(char const *p, size_t len)
{
	if ((p[len - 1] == 's' || p[len - 1] == 'S')
		&& len - 1 && has_esc_slash(p, len - 1))
		return (len - 2);
	if (p[len - 1] == '.')
		return (len - 1);
	return (-1);
}
