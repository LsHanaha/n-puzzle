/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utf_fd_safe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:26:40 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:26:46 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_utf_fd_safe(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		s = s + ft_pututf_fd_safe(s, fd);
}
