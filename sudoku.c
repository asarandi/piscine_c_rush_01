/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:30:17 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	if (c == '.')
		return (1);
	else if ((c >= '1') && (c <= '9'))
		return (1);
	return (0);
}

int	compare_solutions(char tab1[9][9], char tab2[9][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab1[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	copy_matrix(char **av, char tab[9][9])
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		if (ft_strlen(av[i]) != 9)
			return (0);
		j = 0;
		while (j < 9)
		{
			if (!is_valid_char(av[i][j]))
				return (0);
			tab[i - 1][j] = av[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	tab1[9][9];
	char	tab2[9][9];

	if (ac != 10)
		return (write(1, "Error\n", 6));
	if ((copy_matrix(av, tab1)) != 1)
		return (write(1, "Error\n", 6));
	copy_matrix(av, tab2);
	return (solve(tab1, tab2));
}
