/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:25:20 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/11/01 10:36:21 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hex_char(uint8_t c)
{
	ft_putchar(HEX_BASE[c / 16]);
	ft_putchar(HEX_BASE[c % 16]);
}

static void	flush_buf(uint8_t *buf, uint8_t size)
{
	uint8_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(ft_isprint(buf[i]) ? buf[i] : '.');
		++i;
	}
	ft_putchar('\n');
}

static void	print_mem(const uint8_t *data, size_t size, uint8_t *buf,
		uint8_t bpl)
{
	uint8_t	i;

	i = 0;
	while (i < size)
	{
		put_hex_char(data[i]);
		buf[i % bpl] = data[i];
		++i;
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % bpl == 0)
			flush_buf(buf, bpl);
	}
	if (i % bpl)
	{
		ft_putnchar(' ', 2 * (bpl - i % bpl) + ((bpl - i % bpl) / 2) + i % 2);
		flush_buf(buf, i % bpl);
	}
}

void		ft_putmem(const void *data_ptr, size_t size, uint8_t bytes_per_line)
{
	const uint8_t	*data;
	uint8_t			*buf;
	uint8_t			bpl;

	if (!data_ptr || !size)
		return;
	bpl = bytes_per_line ? bytes_per_line : 32;
	if (!(buf = (unsigned char *)malloc(bpl)))
		return ;
	data = data_ptr;
	print_mem(data, size, buf, bpl);
	free(buf);
}
