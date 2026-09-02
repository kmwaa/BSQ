/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_ox.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/08/31 10:56:22 by kcacciab       #+#    #+#                */
/*   Updated: 2026/08/31 10:56:24 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_ox(char	*link_file)
{
	int		fd;
	int		i;
	char	*buf;
	int		res;

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (NULL);
	fd = open(link_file, O_RDONLY);
	res = read(fd, buf, 10);
	i = res;
	while (res == i)
	{
		i = i + 1024;
		free(buf);
		buf = malloc(sizeof(char) *(i));
		if (!buf)
			return (NULL);
		fd = open(link_file, O_RDONLY);
		if (fd < 0)
			return (NULL);
		res = read(fd, buf, i);
	}
	close(fd);
	return (buf);
}
