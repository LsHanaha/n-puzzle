/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:48:10 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/26 19:47:23 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	read_tree(t_rbt *t, const int fd, t_list *buf)
{
	t_rbt	*node;
	long	len;

	if (!(node = ft_rbtfindbyid(t, fd)) || !(node->content) ||
			!(*((char *)(node->content))))
		return (READ_NONE);
	if ((len = ft_strfind(node->content, '\n')) != -1)
	{
		ft_strncpy(buf->content, node->content, len);
		ft_rbtupdatestr(node, ((char *)(node->content)) + len + 1,
				node->content_size - len - 2);
		return (READ_LINE);
	}
	ft_strcpy(buf->content, node->content);
	ft_lstappend(buf, ft_lstfromchr("", GNL_BUFF_SIZE));
	ft_strclr(node->content);
	return (READ_STH);
}

int	read_fd(const int fd, t_list *buf, t_rbt **tptr)
{
	ssize_t	nbyte;
	long	len;

	while (buf->next)
		buf = buf->next;
	len = 0;
	while ((nbyte = read(fd, buf->content, GNL_BUFF_SIZE)))
	{
		if (nbyte == -1)
			return (-1);
		if ((len = ft_strfind(buf->content, '\n')) == -1)
			buf = ft_lstappend(buf, ft_lstfromchr("", GNL_BUFF_SIZE));
		else
		{
			((char *)(buf->content))[len] = '\0';
			if (((char *)(buf->content))[len + 1])
				ft_rbtinsertbyid(tptr, ft_rbtfromchr(fd,
						((char *)(buf->content)) + len + 1, nbyte - len - 1));
			return (READ_LINE);
		}
	}
	return (len ? READ_LINE : READ_NONE);
}

/*
** Returns -1 if there's an error, 1 if it read a line, 0 if it read nothing
*/

int	ft_gnl(const int fd, char **line)
{
	static t_rbt	*t = NULL;
	t_list			*bufflst;
	int				res;
	int				tree_res;

	if (!line)
		return (-1);
	res = 0;
	bufflst = ft_lstfromchr("", GNL_BUFF_SIZE);
	if (!bufflst)
		return (-1);
	if ((tree_res = read_tree(t, fd, bufflst)) != READ_LINE)
		res = read_fd(fd, bufflst, &t);
	if (res == -1)
		return (-1);
	if (tree_res != READ_NONE || res != READ_NONE)
	{
		*line = ft_lsttostr(bufflst, 0);
		res = 1;
	}
	else if (res == READ_NONE)
		ft_rbtrmbyid(&t, fd, &ft_delcontent);
	ft_lstdel(&bufflst, &ft_delcontent);
	return (res);
}
