/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/08/31 10:48:26 by kcacciab       #+#    #+#                */
/*   Updated: 2026/08/31 10:48:28 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str);
char	*get_ox(char	*link_file);
char	***tab_3d(char *buf);

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	char	***tab;

	ft_putstr(argv[0]);
	ft_putstr("\n");
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_putstr(argv[i]);
			ft_putstr("\n");
			i++;
		}
	}
	buf = get_ox("10.ox");
	ft_putstr(buf);
	write (1, "\n", 1);
	tab = tab_3d(buf);
	printf("OK\n");
	ft_putstr(tab);
	free(buf);
	free(tab);
	return (0);
}
