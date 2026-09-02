/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   malloc_tab.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 19:56:22 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/02 19:56:25 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

char	**ft_malloc_tab_1(char *buf)
{
	int		count;
	char	**tab_1;

	count = ft_count_lines(buf);
	tab_1 = malloc((count + 1) * sizeof(char *));
	if (tab_1 == NULL)
		return (NULL);
	return (tab_1);
}

int	**ft_malloc_tab_2(char *buf)
{
	int		count;
	int		**tab_2;

	count = ft_count_lines(buf);
	tab_2 = malloc((count + 1) * sizeof(int *));
	if (tab_2 == NULL)
		return (NULL);
	return (tab_2);
}

char	*ft_malloc_lines_tab_1(char *buf)
{
	int		count;
	char	*lines;

	count = ft_count_colones(buf);
	lines = malloc((count + 1) * sizeof(char));
	if (lines == NULL)
		return (NULL);
	return (lines);
}

int	*ft_malloc_lines_tab_2(char *buf)
{
	int		count;
	int		*lines;

	count = ft_count_colones(buf);
	lines = malloc((count + 1) * sizeof(int));
	if (lines == NULL)
		return (NULL);
	return (lines);
}
