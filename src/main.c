/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:38:58 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/14 14:27:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_vars *v);
int	close_app(int keycode , t_vars *v);

int	main(int ac, char **av)
{
	t_vars	v;

	if (ac == 2)
	{
		if (!init_session(av[1], &v))
			return (0);
		mlx_hoox(v.mlx, 17, 0, close_app, &v);
		mlx_loop(v.mlx);
	}
}