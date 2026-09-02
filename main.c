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

#include "c_bsq.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;
	t_tabs	tabs;

	ft_putstr(argv[0]);
	ft_putstr("\n");
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			buf = get_ox(argv[i]);
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
			free_char_arrays(tabs.tab_char, ft_count_lines(buf));
			free_int_arrays(tabs.tab_int, ft_count_lines(buf));
			free(buf);
			i++;
		}
	}

	return (0);
}
