/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:59:40 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 14:09:55 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int	grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(grid[i][j] + '0');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	solve_skyscrapers(int grid[4][4], int clues[16], int row, int col)
{
	int	num;

	if (row == 4)
		return (check_clues(grid, clues));
	if (col == 4)
		return (solve_skyscrapers(grid, clues, row + 1, 0));
	// if (grid[row][col] != 0)
	// 	return (solve_skyscrapers(grid, clues, row, col + 1));
	num = 0;
	while (++num <= 4)
	{
		grid[row][col] = num;
		if (check_repeat_numbers(grid))
		{
			if (col == 3 && !check_row_clues(grid[row], clues[8 + row], clues[12 + row]))
			{
				grid[row][col] = 0;
				continue ;
			}
			if (row == 3 && !check_cols_clues(grid, col, clues[col], clues[4 + col]))
			{
				grid[row][col] = 0;
				continue;
			}
			if (solve_skyscrapers(grid, clues, row, col + 1))
				return (1);
		}
		grid[row][col] = 0;
	}
	return (0);
}
