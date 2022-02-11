/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:09:02 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 16:09:19 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_dim(char **map)
{
	int	n_rows;
	int	*dim;

	dim = malloc(sizeof(*dim) * 2);
	if (!dim)
		return (NULL);
	n_rows = 0;
	dim[1] = ft_strlen(*map);
	while (*map)
	{
		n_rows++;
		map++;
	}
	dim[0] = n_rows++;
	return (dim);
}
