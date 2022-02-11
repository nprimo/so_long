/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:40:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 18:25:03 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tiles		get_tiles(t_vars *v);
t_tile_type	**init_map(char	*fname, int **dim);

void	render_map(t_vars *v)
{
	int			row;
	int			col;
	t_tile_type	tile;

	row = 0;
	while (row < v->dim[0])
	{
		col = 0;
		while (col < v->dim[1])
		{	
			tile = v->map[row][col];
			mlx_put_image_to_window(v->mlx, v->win,
				v->tiles.img[tile], col * U, row * U);
			col++;
		}
		row++;
	}
}

int	init_session(char *fname, t_vars *v)
{
	int	flag;

	flag = 1;
	v->mlx = mlx_init();
	v->map = init_map(fname, &v->dim);
	if (!v->map)
		flag = 0;
	v->win = mlx_new_window(v->mlx, v->dim[1] * U, v->dim[0] * U, "so_long");
	v->tiles = get_tiles(v);
	render_map(v);
	return (flag);
}
