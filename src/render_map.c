/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:10:25 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/07 11:39:29 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define W v->dim[1] * U
#define H v->dim[0] * U

void	ft_put_cross(t_data *img, t_point p, int clr)
{
	int	count;

	count = 0;
	while (count < U)
	{
		ft_mlx_pixel_put(img, p.y * U + count, p.x * U + count, clr);
		ft_mlx_pixel_put(img, (p.y + 1) * U - count, p.x * U + count, clr);
		count++;
	}
}

void	put_map(t_data *img, t_vars v)
{
	t_point	p;
	int		clr;

	p.x = 0;
	while (p.x < v.dim[0])
	{
		p.y = 0;
		while (p.y < v.dim[1])
		{
			if (v.map[p.x][p.y] == '1')
				clr = 0x00ff0000;
			else if (v.map[p.x][p.y] == 'P')
				clr = 0x00ffffff;
			else if (v.map[p.x][p.y] == 'C')
				clr = 0x0000ff00;
			else if (v.map[p.x][p.y] == 'E')
				clr = 0x000000ff;
			else
				clr = 0x00000000;
			ft_put_cross(img, p, clr);
			p.y++;
		}
		p.x++;
	}
}

void	render_map(t_vars *v)
{
	t_data	img;

	img.img = mlx_new_image(v->mlx, W, H);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.end);
	put_map(&img, *v);
	mlx_put_image_to_window(v->mlx, v->win, img.img, 0, 0);
}
