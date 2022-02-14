/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:06:12 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/14 11:11:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_vars(t_vars *v)
{
	int	count;

	free(v->dim);
	free_split((void **) v->map);
	count = 1;
	while (count <= 5)
	{
		mlx_destroy_image(v->mlx, v->tiles.img[count]);
		count++;
	}
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}
