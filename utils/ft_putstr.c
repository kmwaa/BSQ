/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putstr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kcacciab <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/08/18 08:25:46 by kcacciab       #+#    #+#                */
/*   Updated: 2026/08/18 08:25:48 by kcacciab       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Print a string
 * 
 * @param	str	--	String to print
 */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
