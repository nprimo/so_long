/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:18:52 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 11:27:02 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_content(int fd);

static int	is_valid_char(char c, char *valid_set)
{
	while (*valid_set)
	{
		if (*valid_set == c)
			return (1);
		valid_set++;
	}
	return (0);
}

static int	is_all_valid(char *content, char *valid_set)
{
	while (*content)
	{
		if (!is_valid_char(*content, valid_set) && *content != '\n')
			return (0);
		content++;
	}
	return (1);
}

static int	has_all_char(char *content)
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

int	main(int ac, char **av)
{
	int		fd;
	char	*content;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || fd > 1024)
			return (0);
		content = get_content(fd);
		if (!content)
			return (0);
		ft_putnbr_fd(has_all_char(content), 1);
		ft_putnbr_fd(is_all_valid(content, VALID_CHAR_SET), 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else
	{
		ft_putstr_fd("Insert only 1 argument!\n", 1);
		return (0);
	}
}
