/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:10:25 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 18:31:29 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define W v->dim[1] * U
#define H v->dim[0] * U

void	ft_add_hor_line(t_data img, t_point start, int len, int color);
void	ft_make_sqr(t_data img, t_point start, int len, int color);

void	put_map(t_data *img, t_vars v)
{
	t_point	p;
	int 	clr;

	p.y = 0;
	while (p.y < v.dim[0])
	{
		p.x = 0;
		while (p.x < v.dim[1])
		{
			if (v.map[p.y][p.x] == '1')
				clr = 0x00ff0000;
			else if (v.map[p.y][p.x] == 'P')
				clr = 0x00ffffff;
			else if (v.map[p.y][p.x] == 'C')
				clr = 0x0000ff00;
			else if (v.map[p.y][p.x] == 'E')
				clr = 0x000000ff;
			else
				clr = 0x00000000;
			ft_mlx_pixel_put(img, (p.y + 1) * (U / 2), (p.x + 1) * (U / 2), clr);
			p.y++;
		}
		p.x++;
	}
	(void) img;
}

void	render_map(t_vars *v)
{
	t_data	img;

	img.img = mlx_new_image(v->mlx, W, H);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.end);
	put_map(&img, *v);
	mlx_put_image_to_window(v->mlx, v->win, img.img, 0, 0);
}
