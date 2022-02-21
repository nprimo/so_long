/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:22:17 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/21 11:26:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	ft_printf("Game over!\n");
	free_and_exit(game);
}

int	is_end_game(t_pos pos, t_game *game)
{
	t_tile_type	tile;

	tile = game->map[pos.row][pos.col];
	if (tile == T_EXIT)
		return (1);
	return (0);
}
