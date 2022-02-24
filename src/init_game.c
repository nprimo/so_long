/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:32:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 12:20:59 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_player	init_player(t_tile_type **map);
static t_enemy	init_enemy(t_game *game);

int	init_game(char *fname, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nInitialization mlx failed!\n");
		return (free_and_exit(game));
	}
	game->map = init_map(fname);
	if (!game->map)
	{
		ft_printf("Error\nInitialization map failed!\n");
		return (free_and_exit(game));
	}
	game->win = mlx_new_window(game->mlx,
			get_win_col(game->map) * U,
			get_win_row((void **) game->map) * U, "so_long");
	if (!game->win)
	{
		ft_printf("Error\nInitialization window failed!\n");
		return (free_and_exit(game));
	}
	game->player = init_player(game->map);
	game->enemy = init_enemy(game);
	game->tiles = get_tiles(game);
	game->status = 1;
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
				player.pos.row = row;
				player.pos.col = col;
			}
			if (map[row][col] == T_COLLECTIBLE)
				player.n_collectibles++;
			col++;
		}
		row++;
	}
	return (player);
}

t_enemy	init_enemy(t_game *game)
{
	t_enemy	enemy;
	int		w;
	int		h;

	enemy.pos.col = game->player.ppos.col + 3;
	if (enemy.pos.col > get_win_col(game->map))
		enemy.pos.col = 0;
	enemy.pos.row = 0;
	enemy.img[0]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_ENEMY_0, &w, &h);
	enemy.img[1]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_ENEMY_1, &w, &h);
	enemy.img[2]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_ENEMY_2, &w, &h);
	enemy.img[3]
		= mlx_xpm_file_to_image(game->mlx, REL_PATH_ENEMY_3, &w, &h);
	return (enemy);
}
