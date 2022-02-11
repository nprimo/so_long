/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:15:24 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 10:46:32 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_content(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*content;
	char	*tmp;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		tmp = content;
		content = ft_strjoin(content, buff);
		if (!content)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (content);
}
