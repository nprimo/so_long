/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:16:02 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/29 11:36:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <math.h>
#include <stdio.h>

#define W  1920
#define H  1080

void	ft_add_hor_line(t_data img, t_point start, int len, int color)
{
	while (len > 0)
	{
		ft_mlx_pixel_put(&img, start.x + len, start.y, color);
		len--;
	}
}

void	ft_add_ver_line(t_data img, t_point start, int len, int color)
{
	while (len > 0)
	{
		ft_mlx_pixel_put(&img, start.x, start.y + len, color);
		len--;
	}
}

void	ft_make_sqr(t_data img, t_point start, int len, int color)
{
	ft_add_hor_line(img, start, len, color);
	ft_add_ver_line(img, start, len, color);
	start.y += len;
	ft_add_hor_line(img, start, len, color);
	start.y -= len;
	start.x += len;
	ft_add_ver_line(img, start, len, color);
}

void	ft_make_crl(t_data img, t_point cent, int rad, int color)
{
	double	i;
	double	j;

	i = cent.x - rad;
	while (i < (rad + cent.x))
	{
		j = cent.y + sqrt(pow(rad, 2) - pow(i - cent.y, 2));
		ft_mlx_pixel_put(&img, i, j, color);
		ft_mlx_pixel_put(&img, i, 2 * cent.y - j, color);
		i += 0.01;
	}
}

void	ft_rainbow_hor(t_data img, t_point start, int len)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 0;
	while (r < 250)
	{
		g = 0;
		while (g < 250)
		{
			b = 0;
			while (b < 250)
			{
				color = (0 << 24 | r << 16 | g << 8 | b);
				ft_add_hor_line(img, start, len, color);
				start.y++;
				b += 25;
			}
			g += 25;
		}
		r += 25;
	}
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point	start;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W, H, "Hello world!");
	img.img = mlx_new_image(mlx, W, H);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.end);
	start.x = 0;
	start.y = 0;
	ft_rainbow_hor(img, start, W);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
