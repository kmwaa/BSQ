/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   c_bsq.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/02 19:44:41 by kcacciab       #+#    #+#                */
/*   Updated: 2026/09/02 19:44:44 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_BSQ_H
# define C_BSQ_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct s_tabs
{
	char	**tab_char;
	int		**tab_int;
};

struct s_iter
{
	int		i;
	int		j;
	int		k;
};

typedef struct s_tabs	t_tabs ;
typedef struct s_iter	t_iter ;

void	ft_putstr(char *str);
char	*get_ox(char	*link_file);
char	**ft_tab_1(char *buf);
int		**ft_tab_2(char *buf);
char	*ft_putnbr(int tab_2);
void	free_char_arrays(char **array, int size);
int		ft_count_lines(char *str);
int		ft_count_colones(char *str);
void	ft_putnbr_table(int **tab_2);
void	free_int_arrays(int **array, int size);
void	add_values(t_tabs tabs, char *buf);
void	make_square(t_tabs tabs, char *buf);
char	**ft_malloc_tab_1(char *buf);
char	*ft_malloc_lines_tab_1(char *buf);
int		**ft_malloc_tab_2(char *buf);
int		*ft_malloc_lines_tab_2(char *buf);

#endif