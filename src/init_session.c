/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:40:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 18:01:28 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_player	init_player(t_tile_type **map);

int	init_session(char *fname, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initialization mlx!\n");
		return (free_and_exit(game));
	}
	game->map = init_map(fname);
	if (!game->map)
	{
		ft_printf("Error initialization map!\n");
		return (free_and_exit(game));
	}
	game->win = mlx_new_window(game->mlx,
			get_win_col(game->map) * U,
			get_win_row((void **) game->map) * U, "so_long");
	if (!game->win)
	{
		ft_printf("Error initialization window!\n");
		return (free_and_exit(game));
	}
	game->player = init_player(game->map);
	return (1);
}

static t_player	init_player(t_tile_type **map)
{
	int			row;
	int			col;
	t_player	player;

	player.n_collectibles = 0;
	player.moves = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != END_ROW)
		{
			if (map[row][col] == T_PLAYER)
			{
				player.row = row;
				player.col = col;
			}
			if (map[row][col] == T_COLLECTIBLE)
				player.n_collectibles++;
			col++;
		}
		row++;
	}
	return (player);
}
