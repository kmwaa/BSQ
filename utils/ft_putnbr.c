/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putnbr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: nchaille <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 10:38:18 by nchaille       #+#    #+#                */
/*   Updated: 2026/09/02 10:38:23 by nchaille       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);

void	ft_putnbr(int tab_2)
{
	char	c;

	if (tab_2 != -1)
	{
		c = (tab_2 % 10) + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_line(int *tab_2)
{
	int	i;

	i = 0;
	while (tab_2[i] != -1)
	{
		ft_putnbr(tab_2[i]);
		i++;
	}
}

void	ft_putnbr_table(int **tab_2)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putnbr_line(tab_2[i]);
		ft_putstr("\n");
		i++;
	}
}
