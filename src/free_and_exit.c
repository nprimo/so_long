/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:56:03 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 17:17:10 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_and_exit(t_game *game)
{
	int	count;
	int	n_tiles;

	n_tiles = 5;
	count = 0;
	while (count < n_tiles)
	{
		if (game->tiles.img[count])
			mlx_destroy_image(game->mlx, game->tiles.img[count]);
		count++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	exit(1);
}
