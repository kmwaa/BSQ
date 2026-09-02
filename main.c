/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmwaa <kmwaa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:48:26 by kcacciab          #+#    #+#             */
/*   Updated: 2026/09/02 22:36:38 by kmwaa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_bsq.h"

int	prepa_main(char *buf, t_tabs tabs)
{
	tabs.tab_char = ft_tab_1(buf);
	if (tabs.tab_char == NULL)
		return (1);
	tabs.tab_int = ft_tab_2(buf);
	add_values(tabs, buf);
	ft_putnbr_table(tabs.tab_int);
	make_square(tabs, buf);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_tabs	tabs;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			buf = get_ox(argv[i]);
			if (buf == NULL)
			{
				i++;
				continue ;
			}
			tabs.tab_char = ft_tab_1(buf);
			if (tabs.tab_char == NULL)
				return (1);
			tabs.tab_int = ft_tab_2(buf);
			add_values(tabs, buf);
			ft_putnbr_table(tabs.tab_int);
			make_square(tabs, buf);
			write (1, "\n", 1);
			i = 0;
			while (tabs.tab_char[i])
			{
				ft_putstr(tabs.tab_char[i]);
				ft_putstr("\n");
				i++;
			}
			free_all(tabs, buf);
			i++;
		}
	}
	return (0);
}
