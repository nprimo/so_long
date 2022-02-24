/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:04:44 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 12:41:59 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_tile(t_pos pos, t_game *game);

int	render_enemy(t_game *game)
{
	static int	status = 0;

	if (status > 3)
		status = 0;
	clear_tile(game->enemy.pos, game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy.img[status],
		game->enemy.pos.col * U, game->enemy.pos.row * U);
	status++;
	return (status);
}

void	clear_tile(t_pos pos, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[T_BACKGROUND],
		pos.col * U, pos.row * U);
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[game->map[pos.row][pos.col]],
		pos.col * U, pos.row * U);
}
