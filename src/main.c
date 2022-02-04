/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:00:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 18:21:20 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define W v.dim[1] * U
#define H v.dim[0] * U

void	render_map(t_vars *v);
void	ft_add_hor_line(t_data img, t_point start, int len, int color);
void	ft_rainbow_hor(t_data img, t_point start, int len);

static int	free_all(char **map, int **dim)
{
	free(*dim);
	free_split(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	v;

	if (ac == 2)
	{
		v.map = init_map(av[1]);
		if (!v.map)
			return (0);
		v.dim = get_dim(v.map);
		if (!v.dim)
		{
			free_split(v.map);
			return (0);
		}
		v.mlx = mlx_init();
		v.win = mlx_new_window(v.mlx, W, H, "so_long");
		printf("W, H %d %d\n", W, H);
		printf("col, row %d %d\n", v.dim[1], v.dim[0]);
		render_map(&v);
		mlx_loop(v.mlx);	
		free_all(v.map, &(v.dim));
	}
}
