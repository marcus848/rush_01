/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:04:22 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 14:09:39 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_left_clue(int row[4], int clue)
{
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			visible_count++;
		}
	}
	if (clue != 0 && visible_count != clue)
		return (0);
	return (1);
}

int	check_right_clue(int row[4], int clue)
{
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	i = 4;
	while (--i >= 0)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			visible_count++;
		}
	}
	if (clue != 0 && visible_count != clue)
		return (0);
	return (1);
}

int	check_top_clue(int grid[4][4], int col, int clue)
{
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible_count++;
		}
	}
	if (clue != 0 && visible_count != clue)
		return (0);
	return (1);
}

int	check_bottom_clue(int grid[4][4], int col, int clue)
{
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	i = 4;
	while (--i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible_count++;
		}
	}
	if (clue != 0 && visible_count != clue)
		return (0);
	return (1);
}
