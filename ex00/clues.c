/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:58:00 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 14:09:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	get_clues(int	clues[16], char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		clues[j] = argv[i] - '0';
		i++;
		j++;
	}
}

int	check_clues(int grid[4][4], int clues[16])
{
	int	i;

	if (!check_repeat_numbers(grid))
		return (0);
	i = -1;
	while (++i < 4)
	{
		if (!check_row_clues(grid[i], clues[8 + i], clues[12 + i]))
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		if (!check_cols_clues(grid, i, clues[i], clues[4 + i]))
			return (0);
	}
	return (1);
}

