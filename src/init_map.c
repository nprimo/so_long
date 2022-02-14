/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:35:13 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/14 12:58:03 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		*get_dim(char **map);
int		check_map(char **map);
char	*get_content(int fd);
int		check_content(char *content);

char	**get_map(int fd)
{
	char		*content;
	char		**map;

	content = get_content(fd);
	if (!content)
		return (0);
	if (!check_content(content))
		return (0);
	map = ft_split(content, '\n');
	if (!map || !check_map(map))
	{
		free_split((void **) map);
		return (NULL);
	}
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
	map_row = malloc(sizeof(*map_row) * row_len);
	if (!map_row)
		return (NULL);
	col = 0;
	while (col < row_len)
	{
		map_row[col] = char_to_tile_type(map_char_row[col]);
		col++;
	}
	return (map_row);
}

t_tile_type	**map_char_to_tile_type(char **map_char, int *dim)
{
	t_tile_type	**map;
	int			row;

	map = malloc(sizeof(*map) * (dim[0]));
	if (!map)
		return (NULL);
	row = 0;
	while (row < dim[0])
	{
		map[row] = translate_row(map_char[row]);
		if (!map[row])
			return (NULL);
		row++;
	}
	return (map);
}

t_tile_type	**init_map(char	*fname, int **dim)
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
	*dim = get_dim(map_char);
	if (!(*dim))
		return (free_split((void **) map_char));
	map = map_char_to_tile_type(map_char, *dim);
	if (!map)
		return (free_split((void **) map_char));
	free_split((void **) map_char);
	return (map);
}
