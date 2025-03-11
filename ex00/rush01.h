/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:15:04 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 13:30:29 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdio.h>

int	parse_args(char *argv);
void	get_clues(int	clues[16], char *argv);
void	reset_grid(int grid[4][4]);
int	check_repeat_numbers(int grid[4][4]);
int	check_repeat_rows(int grid[4][4]);
int	check_repeat_cols(int grid[4][4]);
int	check_left_clue(int row[4], int clue);
int	check_right_clue(int row[4], int clue);
int	check_top_clue(int grid[4][4], int col, int clue);
int	check_bottom_clue(int grid[4][4], int col, int clue);
int	check_row_clues(int row[4], int left_clue, int right_clue);
int	check_col_clues(int grid[4][4], int col, int top_clue, int bottom_clue);
int	check_clues(int grid[4][4], int clues[16]);
void	ft_putchar(char c);
void	print_grid(int	grid[4][4]);
int	solve_skyscrapers(int grid[4][4], int clues[16], int row, int col);

#endif // !RUSH01_H
