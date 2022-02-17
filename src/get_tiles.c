/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:34:36 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 18:58:03 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tiles	get_tiles(t_game *game)
{
	int		w;
	int		h;
	t_tiles	tiles;

	tiles.img[T_WALL]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_WALL, &w, &h);
	tiles.img[T_PLAYER]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_PLAYER, &w, &h);
	tiles.img[T_COLLECTIBLE]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_COLLECTIBLE, &w, &h);
	tiles.img[T_EXIT]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_EXIT, &w, &h);
	tiles.img[T_BACKGROUND]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_BACKGROUND, &w, &h);
	return (tiles);
}

/*
int main(void)
{
	t_vars	v;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, 10 * U, 10 * U, "so_long");
	v.tiles = get_tiles(&v);
	mlx_put_image_to_window(v.mlx, v.win, v.tiles.img[T_COLLECTIBLE], U, U);
	mlx_put_image_to_window(v.mlx, v.win, v.tiles.img[T_WALL], 2 * U, 2 * U);
	mlx_put_image_to_window(v.mlx, v.win, v.tiles.img[T_PLAYER], 3 * U, 3 * U);
	mlx_put_image_to_window(v.mlx, v.win, v.tiles.img[T_EXIT], 4 * U, 4 * U);
	mlx_loop(v.mlx);
}
*/
