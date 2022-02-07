/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:18:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/07 17:45:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map);

static char	*get_cont(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	if (fd < 0 || fd > 1024 || !map)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		tmp = map;
		map = ft_strjoin(map, buff);
		if (!map)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (map);
}

char	**get_map(int fd)
{
	char	*cont;
	char	**map;

	cont = get_cont(fd);
	if (!cont)
		return (NULL);
	map = ft_split(cont, '\n');
	if (!map)
		return (free_split(map));
	free(cont);
	return (map);
}

int	*get_dim(char **map)
{
	int	n_rows;
	int	*dim;

	dim = malloc(sizeof(*dim) * 2);
	if (!dim)
		return (0);
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

char	**init_map(char *fname)
{
	int		fd;
	char	**map;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = get_map(fd);
	if (!map || close(fd) == -1 || !check_map(map))
	{
		free_split(map);
		return (NULL);
	}
	return (map);
}
