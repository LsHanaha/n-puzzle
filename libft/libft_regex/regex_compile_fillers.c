/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_compile_fillers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:43:57 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static void	append_range(char from, char to, t_varr *chars)
{
	if (from > to)
	{
		ft_putendl_fd("regex: fill_range: Character range is out of order", 2);
		exit(1);
	}
	while (from <= to)
	{
		ft_varrappend(chars, &from);
		from++;
	}
}

void		fill_range(t_fa_state *state, char const *p,
		size_t new_len, size_t len)
{
	size_t	i;
	int		is_neg_range;
	t_varr	*chars;

	--len;
	is_neg_range = p[new_len + 1] == '^';
	i = new_len + is_neg_range;
	chars = ft_varrnew(sizeof(char));
	while (++i < len)
	{
		if (i < len - 2 && p[i + 1] == '-')
		{
			append_range(p[i], p[i + 2], chars);
			i += 2;
		}
		else
			ft_varrappend(chars, &p[i]);
	}
	state->cmp = is_neg_range ? regex_compare_not_range : regex_compare_range;
	state->data = ft_memalloc(chars->size + 1);
	ft_varrcpy(state->data, chars);
	ft_varrdel(&chars);
}

void		fill_special_sequences(t_fa_state *state, char const *p, size_t len)
{
	state->cmp = regex_compare_special;
	if (p[len - 1] == 's')
		state->data = (void *)(long)RSM_S_SMALL;
	else if (p[len - 1] == 'S')
		state->data = (void *)(long)RSM_S_BIG;
	else if (p[len - 1] == '.')
		state->data = (void *)(long)RSM_DOT;
}

void		fill_regular(t_fa_state *state, char const *p, size_t len)
{
	state->cmp = regex_compare_literally;
	state->data = (void *)(long)p[len - 1];
}
