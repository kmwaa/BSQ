/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmwaa <kmwaa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:51:57 by kcacciab          #+#    #+#             */
/*   Updated: 2026/09/02 22:54:05 by kmwaa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

t_iter	square_loop(t_tabs tabs, t_iter iter, t_square_center *sc)
{
	while (tabs.tab_char[iter.y][iter.x])
	{
		if (tabs.tab_int[iter.y][iter.x] > sc->size)
		{
			sc->size = tabs.tab_int[iter.y][iter.x];
			sc->x = iter.x;
			sc->y = iter.y;
		}
		iter.x++;
	}
	return (iter);
}

void	make_square(t_tabs tabs, char *buf)
{
	t_iter			iter;
	t_square_center	sc;
	int				lines;

	iter.x = 0;
	iter.y = 0;
	sc.x = 0;
	sc.y = 0;
	sc.size = 0;
	lines = ft_count_lines(buf);
	while (iter.y < lines - 1)
	{
		iter = square_loop(tabs, iter, &sc);
		iter.x = 0;
		iter.y++;
	}
	replace_tab(tabs, sc, lines);
}
