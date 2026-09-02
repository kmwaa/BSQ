/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   tab_3d.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: nchaille <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/01 13:22:18 by nchaille       #+#    #+#                */
/*   Updated: 2026/09/01 13:22:25 by nchaille       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

char	**ft_tab_1(char *buf)
{
	char	**tab_1;
	t_iter iter;

	iter.i = 0;
	iter.k = 0;
	iter.j = 0;
	tab_1 = ft_malloc_tab_1(buf);
	if (tab_1 == NULL)
		return (NULL);
	while (buf[iter.i])
	{
		tab_1[iter.j] = ft_malloc_lines_tab_1(buf);
		while (buf[iter.i] != '\n' && buf[iter.i] != '\0')
		{
			tab_1[iter.j][iter.k] = buf[iter.i];
			iter.k++;
			iter.i++;
		}
		tab_1[iter.j][iter.k] = '\0';
		iter.k = 0;
		if (buf[iter.i] == '\n')
			iter.i++;
		iter.j++;
	}
	tab_1[iter.j] = NULL;
	return (tab_1);
}

int	**ft_tab_2(char *buf)
{
	int		i;
	int		j;
	int		k;
	int		**tab_2;

	i = 0;
	j = 0;
	k = 0;
	tab_2 = ft_malloc_tab_2(buf);
	while (buf[i])
	{
		tab_2[j] = ft_malloc_lines_tab_2(buf);
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			tab_2[j][k] = 0;
			k++;
			i++;
		}
		tab_2[j][k] = -1;
		k = 0;
		if (buf[i] == '\n')
			i++;
		j++;
	}
	tab_2[j] = NULL;
	return (tab_2);
}
