/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_available.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:27:23 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	column_available(char c, int y, char tab[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[i][y] == c)
			return (0);
		i++;
	}
	return (1);
}

int	row_available(char c, int x, char tab[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[x][i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	box_available(char c, int x, int y, char tab[9][9])
{
	int x_end;
	int y_end;
	int tmp;

	x = (x / 3) * 3;
	x_end = x + 3;
	y = (y / 3) * 3;
	y_end = y + 3;
	tmp = y;
	while (x < x_end)
	{
		y = tmp;
		while (y < y_end)
		{
			if (tab[x][y] == c)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	is_available(char c, int x, int y, char tab[9][9])
{
	if ((column_available(c, y, tab)) != 1)
		return (0);
	if ((row_available(c, x, tab)) != 1)
		return (0);
	if ((box_available(c, x, y, tab)) != 1)
		return (0);
	return (1);
}

int	print_sudoku(char tab[9][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
			write(1, &tab[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
