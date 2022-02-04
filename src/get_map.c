/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:52:34 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 18:17:01 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/*
int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = get_map(fd);
		while (*map)
		{
			ft_putstr_fd(*map, 1);
			ft_putchar_fd('\n', 1);
			map++;
		}
	}
}
*/
