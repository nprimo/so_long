/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:34:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 13:03:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_win_dim(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (game->map[row][col] != END_ROW)
		col++;
	game->win_dim[1] = col;
	while (game->map[row])
		row++;
	game->win_dim[0] = row;
}

int	get_win_col(char **map)
{
	return (ft_strlen(*map));
}

int	get_win_row(char **map)
{
	int	n_rows;

	n_rows = 0;
	while (*map)
	{
		n_rows++;
		map++;
	}
	return (n_rows);
}
