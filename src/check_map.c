/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:44:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 11:23:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_closed(char **map, int row, int col)
{
	int		*dim;

	dim = get_dim(map);
	if (!dim)
		return (0);
	row = 0;
	while (row < dim[0])
	{
		col = 0;
		while (col < dim[1])
		{
			if ((row == 0 || row == dim[0] - 1
					|| col == 0 || col == dim[1] - 1) && map[row][col] != '1')
			{
				free(dim);
				return (0);
			}
			col++;
		}
		row++;
	}
	free(dim);
	return (1);
}

int	check_map(char **map)
{
	if (!is_closed(map, 0, 0))
		return (0);
	return (1);
}
