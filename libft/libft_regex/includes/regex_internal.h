/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:47:59 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:48:01 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_INTERNAL_H
# define REGEX_INTERNAL_H

# include "regex.h"

enum		e_regex_special_mode
{
	RSM_S_SMALL,
	RSM_S_BIG,
	RSM_DOT
};

enum		e_regex_modifier
{
	ERM_NO,
	ERM_QUESTION,
	ERM_ASTERISK
};

t_fa_state	*fa_state_new(char const *p, size_t *len);

long		check_range(char const *p, size_t len);
long		check_special_sequences(char const *p, size_t len);

void		fill_range(t_fa_state *state, char const *p,
		size_t new_len, size_t len);
void		fill_special_sequences(t_fa_state *state, char const *p,
		size_t len);
void		fill_regular(t_fa_state *state, char const *p, size_t len);

int			regex_compare_literally(int c, void *data);
int			regex_compare_special(int c, void *data);
int			regex_compare_range(int c, void *data);
int			regex_compare_not_range(int c, void *data);

#endif
