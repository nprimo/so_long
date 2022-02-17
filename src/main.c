/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:38:58 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 19:22:54 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	game = pre_setup();
	if (ac == 2)
	{
		init_game(av[1], &game);
		render_map(game);
		mlx_hook(game.win, DESTROY_EVENT, 0, free_and_exit, &game);
		mlx_loop(game.mlx);
	}
	ft_printf("Launch so_long with 1 argument!\n");
	return (0);
}
