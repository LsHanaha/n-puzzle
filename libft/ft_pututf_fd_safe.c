/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututf_fd_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:25:16 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/07/02 15:25:17 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_pututf_fd_safe(char const *c, int fd)
{
	int	len;
	int i;

	len = ft_uchar_len(c);
	write(fd, c, 1);
	i = 1;
	while (i < len && (c[i]))
		write(fd, c + i++, 1);
	return (i);
}
