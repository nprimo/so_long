/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:18:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 16:25:05 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd);
int		check_map(char **map);

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
