/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:32:53 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 12:37:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c, char *valid_set)
{
	while (*valid_set)
	{
		if (*valid_set == c)
			return (1);
		valid_set++;
	}
	return (0);
}

int	is_all_valid(char *content, char *valid_set)
{
	while (*content)
	{
		if (!is_valid_char(*content, valid_set) && *content != '\n')
			return (0);
		content++;
	}
	return (1);
}

int	has_all_char(char *content)
{
	t_count_char	check;

	check.player = 0;
	check.collectible = 0;
	check.exit = 0;
	while (*content)
	{
		if (*content == PLAYER)
			check.player++;
		if (*content == COLLECTIBLE)
			check.collectible++;
		if (*content == EXIT)
			check.exit++;
		content++;
	}
	if (check.player == 1 && check.exit > 0 && check.collectible > 0)
		return (1);
	return (0);
}

int	is_continuos(char *content)
{
	int	flag;

	while (*content)
	{
		flag = 0;
		while (content[flag] && content[flag] == '\n')
			flag++;
		if (flag > 1 && !content[flag])
			return (1);
		else if (flag > 1 && content[flag])
			return (0);
		content++;
	}
	return (1);
}

int	is_rect(char *content)
{
	size_t	tot_len;
	size_t	row_len;

	tot_len = ft_strlen(content);
	row_len = tot_len - ft_strlen(ft_strchr(content, '\n'));
	while (ft_strchr(content, '\n'))
	{
		tot_len = ft_strlen(content);
		if (tot_len - ft_strlen(ft_strchr(content, '\n')) != row_len)
			return (0);
		content += row_len;
		while (*content == '\n')
			content++;
	}
	return (1);
}
