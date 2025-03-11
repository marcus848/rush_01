/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:03:20 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 14:03:55 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row_clues(int row[4], int left_clue, int right_clue)
{
	if (!check_left_clue(row, left_clue))
		return (0);
	if (!check_right_clue(row, right_clue))
		return (0);
	return (1);
}

int	check_col_clues(int grid[4][4], int col, int top_clue, int bottom_clue)
{
	if (!check_top_clue(grid, col, top_clue))
		return (0);
	if (!check_bottom_clue(grid, col, bottom_clue))
		return (0);
	return (1);
}

int	check_repeat_rows(int grid[4][4])
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (grid[i][j] != 0)
			{
				k = j;
				while (++k < 4)
				{
					if (grid[i][j] == grid[i][k])
						return (0);
				}
			}
		}
	}
	return (1);
}

int	check_repeat_cols(int grid[4][4])
{
	int	i;
	int	j;
	int	k;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (grid[i][j] != 0)
			{
				k = i;
				while (++k < 4)
				{
					if (grid[i][j] == grid[k][j])
						return (0);
				}
			}
		}
	}
	return (1);
}

int	check_repeat_numbers(int grid[4][4])
{
	if (!check_repeat_rows(grid))
		return (0);
	if (!check_repeat_cols(grid))
		return (0);
	return (1);
}
