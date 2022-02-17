/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:38:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 19:21:56 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_background(t_game game);

void	render_map(t_game game)
{
	int	row;
	int	col;

	place_background(game);
	row = 0;
	while (game.map[row])
	{
		col = 0;
		while (game.map[row][col] != END_ROW)
		{
			if (game.map[row][col] == T_WALL
					|| game.map[row][col] == T_PLAYER
					|| game.map[row][col] == T_COLLECTIBLE
					|| game.map[row][col] == T_EXIT)
				mlx_put_image_to_window(game.mlx, game.win,
					game.tiles.img[game.map[row][col]],
					col * U, row * U);
			col++;
		}
		row++;
	}
}

void	place_background(t_game game)
{
	int	row;
	int	col;

	row = 0;
	while (game.map[row])
	{
		col = 0;
		while (game.map[row][col] != END_ROW)
		{
			mlx_put_image_to_window(game.mlx, game.win,
				game.tiles.img[T_BACKGROUND],
				col * U, row * U);
			col++;
		}
		row++;
	}
}
