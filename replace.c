/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   replace.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 20:36:54 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/02 20:36:57 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

void	square_replace(int y, int x, int size, t_tabs tabs)
{
	int	i;
	int	j;

	i = size * -1;
	j = size * -1;
	while (i <= size)
	{
		while (j <= size)
		{
			tabs.tab_char[y + j][x + i] = 'X';
			j++;
		}
		j = size * -1;
		i++;
	}
}

t_iter	loop_test(t_iter iter, t_square_center sc, t_tabs tabs)
{
	while (iter.i <= 1 && iter.test == 0)
	{
		while (iter.j <= 1 && iter.test == 0)
		{
			if (tabs.tab_int[sc.y + iter.i][sc.x + iter.j] == sc.size)
				iter.test = 1;
			iter.j++;
		}
		iter.j = -1;
		iter.i++;
	}
	return (iter);
}

void	quadruple_center_test(int y, int x, int size, t_tabs tabs)
{
	t_iter			iter;
	t_square_center	sc;

	sc.x = x;
	sc.y = y;
	sc.size = size;
	iter.i = -1;
	iter.j = -1;
	iter.test = 0;
	if ((tabs.tab_int[y][x + 1] == size)
			&& (tabs.tab_int[y + 1][x + 1] == size)
			&& (tabs.tab_int[y + 1][x] == size))
	{
		square_replace(y, x, size, tabs);
		square_replace(y, x + 1, size, tabs);
		square_replace(y + 1, x + 1, size, tabs);
		square_replace(y + 1, x, size, tabs);
	}
	else if (tabs.tab_int[y][x + 1] != size)
	{
		iter = loop_test(iter, sc, tabs);
		if (iter.test == 0)
			square_replace(y, x, size, tabs);
	}
}

void	replace_tab(t_tabs tabs, t_square_center sc, int lines)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < lines - 1)
	{
		while (tabs.tab_char[y][x])
		{
			if (tabs.tab_int[y][x] == sc.size)
			{
				quadruple_center_test(y, x, sc.size, tabs);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
