/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:38:58 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/24 11:57:28 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_ext(char *fname);
void	run_game(t_game *game, char *fname);

int	main(int ac, char **av)
{
	t_game	game;

	game = pre_setup();
	if (ac == 2)
	{
		if (is_valid_ext(av[1]))
			run_game(&game, av[1]);
		ft_printf("Invalid map format! Need a .ber map\n");
	}
	ft_printf("Launch so_long with 1 argument!\n");
	return (0);
}

int	is_valid_ext(char *fname)
{
	if (ft_strlen(ft_strnstr(fname, ".ber", ft_strlen(fname))) == 4)
		return (1);
	return (0);
}

void	run_game(t_game *game, char *fname)
{
	init_game(fname, game);
	render_map(game);
	mlx_hook(game->win, DESTROY_EVENT, 0, free_and_exit, game);
	mlx_hook(game->win,
		KEYPRESS_EVENT, KEYPRESS_MASK, keypress_handler, game);
	//mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game->mlx);
}
