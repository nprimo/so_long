/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:18:52 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 10:48:47 by nprimo           ###   ########.fr       */
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
