/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:14:02 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 13:33:06 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];
	int	i = 0;

	if (argc != 2)
		return (1);
	if (!parse_args(argv[1]))
		return (1);
	get_clues(clues, argv[1]);
	reset_grid(grid);
	if (solve_skyscrapers(grid, clues, 0, 0))
		print_grid(grid);
	else
	{
		print_grid(grid);
		write(1, "Error\n", 6);
	}
	return (0);
}
