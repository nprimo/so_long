/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:56:03 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 12:41:38 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_and_exit(t_game *game)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (game->tiles.img[count])
			mlx_destroy_image(game->mlx, game->tiles.img[count]);
		if (game->enemy.img[count])
			mlx_destroy_image(game->mlx, game->enemy.img[count]);
		count++;
	}
	if (game->tiles.img[count])
		mlx_destroy_image(game->mlx, game->tiles.img[count]);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	exit(1);
}
