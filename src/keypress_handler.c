/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:11:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/18 18:09:46 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game game);
int		is_movement_key(int keycode);

int	keypress_handler(int keycode, t_game *game)
{
	if (keycode == ESC_KEYCODE)
		return (free_and_exit(game));
	if (is_movement_key(keycode))
		update_game(keycode, game);
	return (1);
}

int	is_movement_key(int keycode)
{
	return (keycode == UP_KEYCODE
		|| keycode == DOWN_KEYCODE
		|| keycode == LEFT_KEYCODE
		|| keycode == RIGHT_KEYCODE);
}

void	print_map(t_game game)
{
	t_pos	c;

	c.row = 0;
	while (game.map[c.row])
	{
		c.col = 0;
		while (game.map[c.row][c.col] != END_ROW)
		{
			ft_printf("%d", game.map[c.row][c.col]);
			c.col++;
		}
		ft_printf("\n");
		c.row++;
	}
	ft_printf("\n");
}
