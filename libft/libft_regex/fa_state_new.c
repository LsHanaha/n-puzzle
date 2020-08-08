/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fa_state_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:42 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

t_fa_state	*fa_state_new(char const *p, size_t *len)
{
	long		new_len;
	t_fa_state	*out;

	out = ft_memalloc(sizeof(t_fa_state));
	if (!p || !len || !(*len))
		return (out);
	if ((new_len = check_range(p, *len)) != -1)
		fill_range(out, p, new_len, *len);
	else if ((new_len = check_special_sequences(p, *len)) != -1)
		fill_special_sequences(out, p, *len);
	else
	{
		new_len = *len - 1;
		fill_regular(out, p, *len);
	}
	*len = new_len;
	return (out);
}
