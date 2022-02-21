/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:23:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/21 12:11:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos		get_new_pos(int keycode, t_pos curr_pos);
int			is_valid_pos(t_pos pos, t_game *game);
void		update_player(t_pos new_pos, t_game *game);
void		update_map(t_pos curr_pos, t_pos new_pos, t_tile_type **map);

void	update_game(int keycode, t_game *game)
{
	t_pos		new_pos;
	t_pos		curr_pos;

	curr_pos = game->player.pos;
	new_pos = get_new_pos(keycode, curr_pos);
	if (is_valid_pos(new_pos, game) == 1)
	{
		if (is_end_game(new_pos, game))
			return (end_game(game));
		update_player(new_pos, game);
		update_map(curr_pos, new_pos, game->map);
		mlx_string_put(game->mlx, game->win,
				0, 0, 0x00000000, ft_itoa(game->player.moves));
	}
}

void	update_map(t_pos curr_pos, t_pos new_pos, t_tile_type **map)
{
	map[curr_pos.row][curr_pos.col] = T_BACKGROUND;
	map[new_pos.row][new_pos.col] = T_PLAYER;
}

int	is_valid_pos(t_pos pos, t_game *game)
{
	t_tile_type	tile;

	if (pos.row < 0
		|| pos.row >= get_win_row((void **)game->map)
		|| pos.col < 0
		|| pos.col >= get_win_col(game->map))
		return (0);
	tile = game->map[pos.row][pos.col];
	if (tile == T_WALL || (tile == T_EXIT && game->player.n_collectibles != 0))
		return (0);
	else
		return (1);
}

t_pos	get_new_pos(int keycode, t_pos curr_pos)
{
	if (keycode == UP_KEYCODE)
		curr_pos.row--;
	if (keycode == DOWN_KEYCODE)
		curr_pos.row++;
	if (keycode == LEFT_KEYCODE)
		curr_pos.col--;
	if (keycode == RIGHT_KEYCODE)
		curr_pos.col++;
	return (curr_pos);
}

void	update_player(t_pos new_pos, t_game *game)
{
	if (game->map[new_pos.row][new_pos.col] == T_COLLECTIBLE)
		game->player.n_collectibles--;
	game->player.moves++;
	game->player.pos = new_pos;
}
