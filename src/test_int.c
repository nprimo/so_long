/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:35:50 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/29 13:06:32 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define W 1900
#define H 1000
#define U 50

void	ft_make_crl(t_data img, t_point cent, int rad, int color);

t_data	put_circle(t_vars *vars, t_point cent)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, W, H);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.end);
	ft_mlx_pixel_put(&img, cent.x, cent.y, 0x00ff0000);
	return (img);
}

int	shut_down(void)
{
	exit(0);
}

int	show_keycode(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		return (close_app(keycode, vars));
	return (0);
}

int	move_pos(int keycode, t_vars *vars)
{
	t_data	img;

	if (keycode == 13)
		vars->pos.y -= U;
	else if (keycode == 0)
		vars->pos.x -= U;
	else if (keycode == 1)
		vars->pos.y += U;
	else if (keycode == 2)
		vars->pos.x += U;
	else if (keycode == 53)
		return (shut_down());
	img = put_circle(vars, vars->pos);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W, H, "Hello world!");
	vars.pos.x = U;
	vars.pos.y = U;
	img = put_circle(&vars, vars.pos);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 0, move_pos, &vars);
	mlx_hook(vars.win, 17, 0, shut_down, &vars);
	mlx_loop(vars.mlx);
}
