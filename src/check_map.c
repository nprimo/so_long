/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:14:54 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 15:13:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_rect(char **map);
int		is_closed(char **map, int row, int col);
int		has_all_char(char **map, int pos);

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

static int	is_all_valid(char **map)
{
	char	**head;
	int		pos;

	head = map;
	pos = 0;
	while (*head)
	{
		while ((*head)[pos])
		{
			if (!is_valid_char((*head)[pos]))
				return (0);
			pos++;
		}
		head++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!is_rect(map))
	{
		ft_putstr_fd("Not rect\n", 1);
		return (0);
	}
	else if (!is_closed(map, 0, 0))
	{
		ft_putstr_fd("Not closed\n", 1);
		return (0);
	}
	else if (!is_all_valid(map))
	{
		ft_putstr_fd("Wrong char inside map\n", 1);
		return (0);
	}
	else if (!has_all_char(map, 0))
	{
		ft_putstr_fd("Missing some special char in map\n", 1);
		return (0);
	}
	else
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
