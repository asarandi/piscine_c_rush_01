/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:27 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/07 17:34:15 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>

int	column_available(char c, int y, char tab[9][9]);
int	row_available(char c, int x, char tab[9][9]);
int	box_available(char c, int x, int y, char tab[9][9]);
int	is_available(char c, int x, int y, char tab[9][9]);
int	print_sudoku(char tab[9][9]);
int	next_position(int *x, int *y, char tab[9][9]);
int	recursion(char tab[9][9]);
int	reverse_next_position(int *x, int *y, char tab[9][9]);
int	reverse_recursion(char tab[9][9]);
int	solve(char tab1[9][9], char tab2[9][9]);
int	ft_strlen(char *s);
int	is_valid_char(char c);
int	compare_solutions(char tab1[9][9], char tab2[9][9]);
int	copy_matrix(char **av, char tab[9][9]);

#endif
