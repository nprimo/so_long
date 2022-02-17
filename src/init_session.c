/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:40:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 16:03:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_session(char *fname, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initialization mlx!\n");
		return	(free_and_exit(game));
	}
	game->map = init_map(fname);
	if (!game->map)
	{
		ft_printf("Error initialization map!\n");
		return (free_and_exit(game));
	}
	// get_win_dim(game);
	return (1);
}
