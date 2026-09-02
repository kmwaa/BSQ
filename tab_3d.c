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

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	ft_count_lines(char *str);

char	***tab_3d(char *buf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;

	tab = ft_malloc_gr_tab(buf);
	if (tab == NULL)
		return (NULL);
	tab[0] = ft_malloc_pt_tab(buf);
	if (tab[0] == NULL)
		return (NULL);
	tab[1] = ft_malloc_pt_tab(buf);
	if (tab[1] == NULL)
		return (NULL);
	while (buf[i])
	{
		tab[0][j] = ft_malloc_lines(buf);
		tab[1][j] = ft_malloc_lines(buf);
		while (buf[i] != '\n')
		{
			tab[0][j][k] = buf[i];
			i++;
			k++;
		}
		tab[0][j][k] = '\0';
		j++;
		i++;
		k = 0;
	}
	return (tab);
}

char	***ft_malloc_gr_tab(char *buf)
{
	int		count;
	char	***gr_tab;

	gr_tab = malloc(2 * sizeof(char **));
	if (gr_tab == NULL)
		return (NULL);
	return (gr_tab);
}

char	**ft_malloc_pt_tab(char *buf)
{
	int		count;
	char	**pt_tab;

	count = ft_count_lines(buf) + 1;
	pt_tab = malloc(count * sizeof(char *));
	if (pt_tab == NULL)
		return (NULL);
	return (pt_tab);
}

char	*ft_malloc_lines(char *buf)
{
	int		count;
	char	*lines;

	count = ft_count_colones(buf);
	lines = malloc((count + 1) * sizeof(char));
	if (lines == NULL)
		return (NULL);
	return (lines);
}
