/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:16:02 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/28 17:46:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define W  1920
#define H  1080

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	ft_add_hor_line(t_data img, t_point start, int len, int color)
{
	while (len > 0)
	{
		ft_mlx_pixel_put(&img, start.x + len, start.y, color);
		len--;
	}
}

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
	start.x = 50;
	start.y = 50;
	ft_add_hor_line(img, start, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
