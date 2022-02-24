/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:47:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 12:30:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	pre_setup(void)
{
	t_game	game;
	int		c;

	game.mlx = NULL;
	game.win = NULL;
	game.map = NULL;
	c = 0;
	while (c < 4)
	{
		game.tiles.img[c] = NULL;
		game.enemy.img[c] = NULL;
		c++;
	}
	game.tiles.img[4] = NULL;
	return (game);
}
