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

int	test_case(t_tabs tabs, int y, int x, t_square_center sc)
{
	if (x < 0)
		return (-1);
	if (y < 0)
		return (-1);
	if (x >= sc.x)
		return (-1);
	if (y >= sc.y)
		return (-1);
	if (tabs.tab_char[y][x] == '\0')
		return (-1);
	if (tabs.tab_char[y][x] == 'o')
		return (-1);
	return (0);
}

void	seek(t_tabs tabs, t_iter iter, t_square_center sc, int dist)
{
	int				test;

	test = 0;
	iter.i = dist * -1;
	iter.j = dist * -1;
	while (iter.i <= dist && test == 0)
	{
		while (iter.j <= dist && test == 0)
		{
			test = test_case(tabs,
					iter.y + iter.i, iter.x + iter.j, sc);
			iter.j++;
		}
		iter.j = dist * -1;
		iter.i++;
	}
	if (!tabs.tab_int[iter.y][iter.x])
		tabs.tab_int[iter.y][iter.x] = 0;
	if (test == 0)
	{
		tabs.tab_int[iter.y][iter.x] = tabs.tab_int[iter.y][iter.x] + 1;
		seek(tabs, iter, sc, dist + 1);
	}
}

void	add_values(t_tabs tabs, char *buf)
{
	t_iter			iter;
	t_square_center	sc;

	iter.x = 0;
	iter.y = 0;
	sc.y = ft_count_lines(buf);
	sc.x = ft_count_colones(buf);
	while (iter.y < ft_count_lines(buf))
	{
		while (tabs.tab_char[iter.y][iter.x])
		{
			seek(tabs, iter, sc, 1);
			iter.x++;
		}
		iter.x = 0;
		iter.y++;
	}
}
