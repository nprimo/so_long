/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:14:54 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 11:51:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_checker
{
	int	clt;
	int	ext;
	int	str;
}	t_checker;

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

int	is_rect(char **map)
{
	size_t	len;

	len = ft_strlen(*map);
	map++;
	while (*map)
	{
		if (len != ft_strlen(*map))
			return (0);
		map++;
	}
	return (1);
}

int	is_closed(char **map)
{
	int	*dim;
	int	row;
	int	col;

	dim = get_dim(map);
	if (!dim)
		return (0);
	row = 0;
	while (row < dim[0])
	{
		col = 0;
		while (col < dim[1])
		{
			if ((row == 0 || row == dim[0] - 1) && map[row][col] != '1')
				return (0);
			if ((col == 0 || (col == dim[1] - 1)) && map[row][col] != '1')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	is_valid_map(char **map)
{
	t_checker	check;

	check.clt = 0;
	check.ext = 0;
	check.str = 0;
	while (*map)
	{
		while (**map)
		{
			if (!is_valid_char(**map))
				return (0);
			if (**map == 'C')
				check.clt++;
			else if (**map == 'E')
				check.ext++;
			else if (**map == 'P')
				check.str++;
			(*map)++;
		}
		map++;
	}
	if (check.clt == 0 || check.ext == 0 || check.str != 1)
		return (0);
	return (1);
}

/*
int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = get_map(fd);
		if (!map)
			return (1);
		is_rect(map);
		is_closed(map);
		is_valid_map(map);
	}
	return (0);
}
*/
