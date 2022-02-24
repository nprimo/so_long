/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:15:08 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 13:15:38 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_tile(t_pos pos, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[T_BACKGROUND],
		pos.col * U, pos.row * U);
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[game->map[pos.row][pos.col]],
		pos.col * U, pos.row * U);
	if (pos.row == 0 && pos.col < 2)
		display_moves(game);
}
