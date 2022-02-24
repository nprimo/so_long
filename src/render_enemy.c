/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:04:44 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 13:03:35 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_tile(t_pos pos, t_game *game);
static void	update_enemy(t_game *game);
static int	is_enemy_on_player(t_game *game);

int	render_enemy(t_game *game)
{
	static int	status = 0;

	if (status > 3)
		status = 0;
	clear_tile(game->enemy.pos, game);
	update_enemy(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy.img[status],
		game->enemy.pos.col * U, game->enemy.pos.row * U);
	if (is_enemy_on_player(game))
	{
		ft_printf("You loose!\n");
		return (free_and_exit(game));
	}
	status++;
	return (status);
}

static void	clear_tile(t_pos pos, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[T_BACKGROUND],
		pos.col * U, pos.row * U);
	mlx_put_image_to_window(game->mlx, game->win,
		game->tiles.img[game->map[pos.row][pos.col]],
		pos.col * U, pos.row * U);
	if (pos.row == 0 && pos.col < 2)
		display_moves(game);
}

static void	update_enemy(t_game *game)
{
	t_enemy	new_enemy;

	new_enemy = game->enemy;
	new_enemy.pos.row++;
	new_enemy.pos.col++;
	if (new_enemy.pos.row >= get_win_row((void **) game->map))
		new_enemy.pos.row = 0;
	if (new_enemy.pos.col >= get_win_col(game->map))
		new_enemy.pos.col = 0;
	game->enemy = new_enemy;
}

static int	is_enemy_on_player(t_game *game)
{
	if (game->enemy.pos.row == game->player.pos.row
		&& game->enemy.pos.col == game->player.pos.col)
		return (1);
	return (0);
}
