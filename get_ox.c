/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmwaa <kmwaa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:56:22 by kcacciab          #+#    #+#             */
/*   Updated: 2026/09/02 22:31:32 by kmwaa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

char	*mal_op_read(char *buf, int *fd, int *res, char *link_file)
{
	*fd = open(link_file, O_RDONLY);
	if (*fd < 0)
	{
		free(buf);
		return (NULL);
	}
	*res = read(*fd, buf, 10);
	if (*res < 0)
	{
		close(*fd);
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*read_if(char *buf, int *fd, char *link_file)
{
	if (!buf)
		return (NULL);
	close(*fd);
	*fd = open(link_file, O_RDONLY);
	if (*fd < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*get_ox(char	*link_file)
{
	int		fd;
	int		i;
	char	*buf;
	int		res;

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (NULL);
	buf = mal_op_read(buf, &fd, &res, link_file);
	if (!buf)
		return (NULL);
	buf[res] = '\0';
	i = res;
	while (res == i)
	{
		i = i + 1024;
		free(buf);
		buf = malloc(sizeof(char) *(i + 1));
		read_if(buf, &fd, link_file);
		res = read(fd, buf, i);
		buf[res] = '\0';
	}
	close(fd);
	return (buf);
}
