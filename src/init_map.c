/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:35:13 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 15:51:19 by nprimo           ###   ########.fr       */
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

char	**init_map(int fd)
{
	char		*content;
	char		**map;

	content = get_content(fd);
	if (!content)
		return (0);
	if (!check_content(content))
		return (0);
	map = get_map(fd);
	if (!map || !check_map(map))
	{
		free_split(map);
		return (NULL);
	}
	return (map);
}
