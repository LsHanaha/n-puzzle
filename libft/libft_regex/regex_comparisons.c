/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_comparisons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:43 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

int	regex_compare_literally(int c, void *data)
{
	return (c == (int)(long)data);
}

int	regex_compare_special(int c, void *data)
{
	int	mode;

	mode = (int)(long)data;
	if (mode == RSM_S_SMALL)
		return (ft_isspace(c));
	if (mode == RSM_S_BIG)
		return (c != '\n' && ft_isspace(c));
	return (1);
}

int	regex_compare_range(int c, void *data)
{
	return (ft_strfind(data, c) != -1);
}

int	regex_compare_not_range(int c, void *data)
{
	return (!regex_compare_range(c, data));
}
