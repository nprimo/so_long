/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:34:31 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 17:12:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_win_col(char **map)
{
	return (ft_strlen(*map));
}

int	get_win_row(char **map)
{
	int	n_rows;

	n_rows = 0;
	while (*map)
	{
		n_rows++;
		map++;
	}
	return (n_rows);
}
