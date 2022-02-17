/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:35:13 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 16:19:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

char	**get_map(int fd)
{
	char		*content;
	char		**map;

	map = NULL;
	content = get_content(fd);
	if (!content)
		return (NULL);
	if (check_content(content))
		map = ft_split(content, '\n');
	if (map && !check_map(map))
	{
		free_split((void **) map);
		map = NULL;
	}
	free(content);
	return (map);
}

t_tile_type	char_to_tile_type(char c)
{
	if (c == WALL)
		return (T_WALL);
	if (c == COLLECTIBLE)
		return (T_COLLECTIBLE);
	if (c == PLAYER)
		return (T_PLAYER);
	if (c == EXIT)
		return (T_EXIT);
	return (0);
}

t_tile_type	*translate_row(char	*map_char_row)
{
	t_tile_type	*map_row;
	size_t		row_len;
	size_t		col;

	row_len = ft_strlen(map_char_row);
	map_row = malloc(sizeof(*map_row) * (row_len + 1));
	if (!map_row)
		return (NULL);
	col = 0;
	while (col < row_len)
	{
		map_row[col] = char_to_tile_type(map_char_row[col]);
		col++;
	}
	map_row[col] = END_ROW;
	return (map_row);
}

t_tile_type	**map_char_to_tile_type(char **map_char, int win_row)
{
	t_tile_type	**map;
	int			row;

	map = malloc(sizeof(*map) * (win_row + 1));
	if (!map)
		return (NULL);
	row = 0;
	while (row < win_row)
	{
		map[row] = translate_row(map_char[row]);
		if (!map[row])
			return (NULL);
		row++;
	}
	map[row]= NULL;
	return (map);
}

t_tile_type	**init_map(char	*fname)
{
	int			fd;
	char		**map_char;
	t_tile_type	**map;

	fd = open(fname, O_RDONLY);
	if (fd < 0 || fd > 10)
		return (NULL);
	map_char = get_map(fd);
	if (!map_char)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	map = map_char_to_tile_type(map_char, get_win_row(map_char));
	if (!map)
		return (free_split((void **) map_char));
	free_split((void **) map_char);
	return (map);
}
