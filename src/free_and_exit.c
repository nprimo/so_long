/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:56:03 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 12:20:38 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_and_exit(t_game *game)
{
	int	count;

	count = 4;
	while (count > 0)
	{
		if (game->tiles.img[count])
			mlx_destroy_image(game->mlx, game->tiles.img[count]);
		count--;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	exit(1);
}
