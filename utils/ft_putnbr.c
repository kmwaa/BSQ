/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmwaa <kmwaa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:38:18 by nchaille          #+#    #+#             */
/*   Updated: 2026/09/02 23:21:01 by kmwaa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	while (tab_2[i] != NULL)
	{
		ft_putnbr_line(tab_2[i]);
		ft_putstr("\n");
		i++;
	}
}
