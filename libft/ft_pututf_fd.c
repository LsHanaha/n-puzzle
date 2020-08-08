/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:34 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_pututf_fd(char const *c, int fd)
{
	int	len;

	if (!(*c & 0b10000000))
		len = 1;
	else if ((*c & 0b11110000) == 0b11110000)
		len = 4;
	else if ((*c & 0b11100000) == 0b11100000)
		len = 3;
	else
		len = 2;
	write(fd, c, len);
	return (len);
}
