/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:47:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 12:08:11 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pre_setup(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->tiles.img[0] = NULL;
	game->tiles.img[1] = NULL;
	game->tiles.img[2] = NULL;
	game->tiles.img[3] = NULL;
}
