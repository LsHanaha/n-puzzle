/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:47:48 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:47:51 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "libft.h"

/*
**	Supported tokens:
**			matching string literally
**	[a-zA]	matching to range
**	?		one or zero of previous character
**	*		zero or more of previous character
**	\s		whitespace
**	\S		whitespace (except \n)
**	.		for any character.
**	[^']	any character except
**
**	Special characters ?, *, . CANNOT be escaped. Use []
*/

typedef	struct	s_fa_state
{
	int					(*cmp)(int c, void *data);
	void				*data;
	struct s_fa_state	*next;
	struct s_fa_state	*enext;
}				t_fa_state;

/*
**	Start points to the beginning of the match, end -- to the first char after
*/

typedef struct	s_regex_match
{
	char	*start;
	char	*end;
}				t_regex_match;

t_fa_state		*ft_regex_compile(char const *pattern);
int				ft_regex_match(t_fa_state *regex, char const *s);
char			*ft_regex_pmatch(t_fa_state *regex, char *s);
t_regex_match	ft_regex_search(t_fa_state *regex, char *s);
void			ft_regex_del(t_fa_state **regex);

#endif
