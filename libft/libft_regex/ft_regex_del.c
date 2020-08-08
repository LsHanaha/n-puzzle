/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:42 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:43:36 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static void		hash_states_delete_contents(t_fa_state *state, t_htab *states)
{
	void	*next_state;

	if (ft_htgetid(states, &state, sizeof(void *)) == -1)
		ft_htadd(states, ft_hilnew(&state, sizeof(void *), NULL, 0));
	if (state->cmp != regex_compare_literally
		&& state->cmp != regex_compare_special && state->data)
	{
		free(state->data);
		state->data = NULL;
	}
	if (state->next)
	{
		next_state = state->next;
		state->next = NULL;
		hash_states_delete_contents(next_state, states);
	}
	if (state->enext)
	{
		next_state = state->enext;
		state->enext = NULL;
		hash_states_delete_contents(next_state, states);
	}
}

static uint32_t	get_n_states(t_fa_state *state)
{
	if (!state)
		return (0);
	return (1 + (state->next != state ? get_n_states(state->next) : 0)
			+ get_n_states(state->enext));
}

void			ft_regex_del(t_fa_state **regex)
{
	t_htab		*states;
	uint32_t	i;

	if (!regex || !(*regex))
		return ;
	states = ft_htnew(ft_nextprime(get_n_states(*regex)),
			BASE_ASCII, ALTBASE_ASCII);
	hash_states_delete_contents(*regex, states);
	i = 0;
	while (i < states->size)
	{
		if (states->items[i] != NULL && states->items[i] != DELETED_HI)
			free((void *)(*(uintptr_t *)states->items[i]->key));
		++i;
	}
	ft_htdel(&states, ft_hidel);
	*regex = NULL;
}
