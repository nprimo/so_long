/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:34:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 18:00:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_win_col(t_tile_type **map)
{
	t_tile_type	*map_row;
	int			col;

	col = 0;
	map_row = *map;
	while (map_row[col] != END_ROW)
		col++;
	return (col);
}

int	get_win_row(void **map)
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
