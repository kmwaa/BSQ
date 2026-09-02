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

char	**tab_1(char *buf)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	j = 0;
	tab[j] = ft_malloc_tab(buf);
	if (tab[j] == NULL)
		return (NULL);
	while (buf[i])
	{
		tab[j][k] = ft_malloc_lines(buf);
		while (buf[i] != '\n')
		{
			tab[j][k++] = buf[i++];
		}
		tab[j][k] = '\0';
		k = 0;
		i++;
		j++;
	}
	return (tab);
}

char	**tab_2(void)
{
	int		i;
	int		j;
	int		k;
	char	**tab2;

	i = 0;
	k = 0;
	j = 0;
	tab[j] = ft_malloc_tab(buf);
	if (tab[j] == NULL)
		return (NULL);
	while (buf[i])
	{
		tab[j][k] = ft_malloc_lines(buf);
		while (buf[i] != '\n')
		{
			tab[j][k++] = '0';
		}
		tab[j][k] = '\0';
		k = 0;
		i++;
		j++;
	}
	return (tab2);
}

char	**ft_malloc_tab(char *buf)
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
