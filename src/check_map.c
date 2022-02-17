/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:44:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 18:05:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_closed(char **map);
static int	get_col(char **map);

int	check_map(char **map)
{
	if (!is_closed(map))
		return (0);
	return (1);
}

static int	is_closed(char **map)
{
	int		win_row;
	int		win_col;
	int		row;
	int		col;

	win_row = get_win_row((void **) map);
	win_col = get_col(map);
	row = 0;
	while (row < win_row)
	{
		col = 0;
		while (col < win_col)
		{
			if ((row == 0 || row == win_row - 1
					|| col == 0 || col == win_col - 1) && map[row][col] != '1')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

static int	get_col(char **map)
{
	int	col;

	col = 0;
	while (map[0][col])
		col++;
	return (col);
}
