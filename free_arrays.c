/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   free_arrays.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 08:56:28 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/02 08:56:30 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

void	free_all(t_tabs tabs, char *buf)
{
	free_char_arrays(tabs.tab_char, ft_count_lines(buf));
	free_int_arrays(tabs.tab_int, ft_count_lines(buf));
	free(buf);
}

void	free_char_arrays(char **array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}



void	free_int_arrays(int **array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
