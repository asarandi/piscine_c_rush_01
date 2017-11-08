/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:23:51 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:35:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	next_position(int *x, int *y, char tab[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab[i][j] == '.')
			{
				*x = i;
				*y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	recursion(char tab[9][9])
{
	int		x;
	int		y;
	char	c;

	if (next_position(&x, &y, tab) == 0)
		return (1);
	c = '1';
	while (c <= '9')
	{
		if (is_available(c, x, y, tab))
		{
			tab[x][y] = c;
			if (recursion(tab) == 1)
				return (1);
			else
				tab[x][y] = '.';
		}
		c++;
	}
	return (0);
}

int	reverse_next_position(int *x, int *y, char tab[9][9])
{
	int i;
	int j;

	i = 8;
	while (i >= 0)
	{
		j = 8;
		while (j >= 0)
		{
			if (tab[i][j] == '.')
			{
				*x = i;
				*y = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	reverse_recursion(char tab[9][9])
{
	int		x;
	int		y;
	char	c;

	if (reverse_next_position(&x, &y, tab) == 0)
		return (1);
	c = '1';
	while (c <= '9')
	{
		if (is_available(c, x, y, tab))
		{
			tab[x][y] = c;
			if (reverse_recursion(tab) == 1)
				return (1);
			else
				tab[x][y] = '.';
		}
		c++;
	}
	return (0);
}

int	solve(char tab1[9][9], char tab2[9][9])
{
	if (recursion(tab1) != 1)
		return (write(1, "Error\n", 6));
	if (reverse_recursion(tab2) != 1)
		return (write(1, "Error\n", 6));
	if (compare_solutions(tab1, tab2) == 0)
		return (write(1, "Error\n", 6));
	return (print_sudoku(tab1));
}
