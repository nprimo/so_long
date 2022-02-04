/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:50:23 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 15:23:52 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_checker
{
	int	clt;
	int	ext;
	int	str;
}	t_checker;

int	is_rect(char **map)
{
	size_t	len;
	char	**head;

	head = map;
	len = ft_strlen(*head);
	head++;
	while (*head)
	{
		if (len != ft_strlen(*head))
			return (0);
		head++;
	}
	return (1);
}

int	is_closed(char **map, int row, int col)
{
	int		*dim;

	dim = get_dim(map);
	if (!dim)
		return (0);
	row = 0;
	while (row < dim[0])
	{
		col = 0;
		while (col < dim[1])
		{
			if ((row == 0 || row == dim[0] - 1
					|| col == 0 || col == dim[1] - 1) && map[row][col] != '1')
			{
				free(dim);
				return (0);
			}
			col++;
		}
		row++;
	}
	free(dim);
	return (1);
}

int	has_all_char(char **map, int pos)
{
	t_checker	check;
	char		**head;

	head = map;
	check.clt = 0;
	check.ext = 0;
	check.str = 0;
	while (*head)
	{
		pos = 0;
		while ((*head)[pos])
		{
			if ((*head)[pos] == 'C')
				check.clt++;
			else if ((*head)[pos] == 'E')
				check.ext++;
			else if ((*head)[pos] == 'P')
				check.str++;
			pos++;
		}
		head++;
	}
	if (check.clt == 0 || check.ext == 0 || check.str != 1)
		return (0);
	return (1);
}
