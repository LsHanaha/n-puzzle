/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_compile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:42 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

static enum e_regex_modifier	set_modifier(char const *p, size_t len)
{
	if (p[len - 1] == '?' && len - 1)
		return (ERM_QUESTION);
	if (p[len - 1] == '*' && len - 1)
		return (ERM_ASTERISK);
	return (ERM_NO);
}

static int						data_is_str(int (*f)(int c, void *data))
{
	return (f != regex_compare_literally && f != regex_compare_special);
}

static void						add_state(char const *p, size_t *len,
		t_fa_state **states)
{
	t_fa_state				*new_state;
	enum e_regex_modifier	modifier;

	modifier = set_modifier(p, *len);
	if (modifier != ERM_NO)
	{
		(*len)--;
		new_state = fa_state_new(p, len);
		new_state->enext = *states;
		new_state->next = fa_state_new(NULL, NULL);
		new_state->next->enext = *states;
		if (modifier == ERM_ASTERISK)
		{
			new_state->next->cmp = new_state->cmp;
			new_state->next->next = new_state->next;
			new_state->next->data = data_is_str(new_state->cmp) ?
					ft_strdup(new_state->data) : new_state->data;
		}
	}
	else
	{
		new_state = fa_state_new(p, len);
		new_state->next = *states;
	}
	*states = new_state;
}

t_fa_state						*ft_regex_compile(char const *p)
{
	t_fa_state	*out;
	size_t		len;

	if (!p || !(*p))
		return (NULL);
	if (!(out = fa_state_new(NULL, 0)))
		return (NULL);
	len = ft_strlen(p);
	while (len > 0)
		add_state(p, &len, &out);
	return (out);
}
