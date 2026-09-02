/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   make_square.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 09:51:57 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/02 09:52:00 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

struct tabs
{
    char	**tab_char; 
	int 	**tab_int;
};


struct square_center
{
	int	size;
    int	x; 
	int	y;
};

typedef struct tabs Tabs ;
typedef struct square_center Square_Center ;

int	ft_count_lines(char *str);
int	ft_count_colones(char *str);

void square_replace(int y, int x, int size, Tabs tabs)
{
	int	i;
	int	j;

	i = size * -1;
	j = size * -1;
	while (i <= size)
	{
		while (j <= size)
		{
			tabs.tab_char[y + j][x + i] = 'X';
			j++;
		}
		j = size * -1;
		i++;
	}
}

void quadruple_center_test(int y, int x, int size, Tabs tabs)
{
	int i;
	int j;
	int test;

	i = -1;
	j = -1;
	test = 0;
	if (tabs.tab_int[y][x + 1] == size)
	{
		if (tabs.tab_int[y + 1][x + 1] == size)
		{
			if (tabs.tab_int[y + 1][x] == size)
			{
				square_replace(y, x, size, tabs);
				square_replace(y, x + 1, size, tabs);
				square_replace(y + 1, x + 1, size, tabs);
				square_replace(y + 1, x, size, tabs);
			}
		}
	}
	else if (tabs.tab_int[y][x + 1] != size)
	{
		while (i <= 1 && test == 0)
		{
			while (j <= 1 && test == 0)
			{
				if (tabs.tab_int[y + i][x + j] == size)
					test = 1;
				j++;
			}
			j = -1;
			i++;
		}
		if (test == 0)
			square_replace(y, x, size, tabs);
	}
}

void	replace_tab(Tabs tabs, Square_Center sc, int lines)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < lines - 1)
	{
		while (tabs.tab_char[y][x])
		{
			if (tabs.tab_int[y][x] == sc.size)
			{
				quadruple_center_test(y, x, sc.size, tabs);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	make_square(Tabs tabs, char *buf)
{
	int x;
	int y;
	Square_Center sc;
	int lines;

	x = 0;
	y = 0;
	sc.x = 0;
	sc.y = 0;
	sc.size = 0;
	lines = ft_count_lines(buf);
	while (y < lines - 1)
	{
		while (tabs.tab_char[y][x])
		{
			if (tabs.tab_int[y][x] > sc.size)
			{
				sc.size = tabs.tab_int[y][x];
				sc.x = x;
				sc.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	replace_tab(tabs, sc, lines);
}
