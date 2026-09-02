/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   add_values.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/01 13:23:22 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/01 13:23:24 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

int	test_case(t_tabs tabs, int y, int x, int size_y, int size_x)
{
	if (x < 0)
		return (-1);
	if (y < 0)
		return (-1);
	if (x >= size_x)
		return (-1);
	if (y >= size_y)
		return (-1);
	if (tabs.tab_char[y][x] == '\0')
		return (-1);
	if (tabs.tab_char[y][x] == 'o')
		return (-1);
	return (0);
}

void	seek(t_tabs tabs, int y, int x, int size_y, int size_x, int dist)
{
	int	i;
	int	j;
	int	test;

	test = 0;
	i = dist * -1;
	j = dist * -1;
	while (i <= dist && test == 0)
	{
		while (j <= dist && test == 0)
		{
			test = test_case(tabs, y + i, x + j, size_y, size_x);
			j++;
		}
		j = dist * -1;
		i++;
	}
	if (!tabs.tab_int[y][x])
		tabs.tab_int[y][x] = 0;
	if (test == 0)
	{
		tabs.tab_int[y][x] = tabs.tab_int[y][x] + 1;
		seek(tabs, y, x, size_y, size_x, dist + 1);
	}
}

void	add_values(t_tabs tabs, char *buf)
{
	int	x;
	int	y;
	int	lines;
	int	columns;

	x = 0;
	y = 0;
	lines = ft_count_lines(buf);
	columns = ft_count_colones(buf);
	while (y < ft_count_lines(buf))
	{
		while (tabs.tab_char[y][x])
		{
			seek(tabs, y, x, lines, columns, 1);
			x++;
		}
		x = 0;
		y++;
	}
}
