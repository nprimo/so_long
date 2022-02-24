/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:47:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 17:18:59 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	pre_setup(void)
{
	t_game	game;
	int		c;
	int		n_tiles;

	game.mlx = NULL;
	game.win = NULL;
	game.map = NULL;
	n_tiles = 5;
	c = 0;
	while (c < n_tiles)
	{
		game.tiles.img[c] = NULL;
		c++;
	}
	return (game);
}
