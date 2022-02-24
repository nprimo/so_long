/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:36:24 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 11:45:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	int	col;

	col = 0;
	while (col < 2)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tiles.img[T_BACKGROUND], col * U, 0);
		mlx_put_image_to_window(game->mlx, game->win,
			game->tiles.img[T_WALL], col * U, 0);
		col++;
	}
	mlx_string_put(game->mlx, game->win,
		U / 4, U / 4, 0x00000000, ft_itoa(game->player.moves));
	ft_printf("Moves: %d\n", game->player.moves);
}
