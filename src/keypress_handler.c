/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:11:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/18 10:22:57 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_handler(int keycode, t_game *game)
{
	if (keycode == ESC_KEYCODE)
		return (free_and_exit(game));
	if (keycode == UP_KEYCODE
		|| keycode == DOWN_KEYCODE
		|| keycode == LEFT_KEYCODE
		|| keycode == RIGHT_KEYCODE)
		ft_printf("Update map and render it again!\n");
	return (game->player.row);
}
