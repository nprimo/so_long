/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:35:13 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 16:12:50 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_map(int fd)
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
		free_split(map);
		return (NULL);
	}
	return (map);
}