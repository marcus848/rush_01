/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:16:10 by marcudos          #+#    #+#             */
/*   Updated: 2025/03/11 14:09:52 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	reset_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = 0;
	}
}

int	parse_args(char *argv)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		if (!(argv[i] >= '1' && argv[i] <= '4'))
			return (0);
		else
			count++;
		i++;
		if (argv[i] != ' ' && argv[i])
			return (0);
	}
	if (count != 16)
		return (0);
	return (1);
}
