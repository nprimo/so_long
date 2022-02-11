/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:17:52 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/11 13:26:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_all_valid(char *content, char *valid_set);
int	has_all_char(char *content);
int	is_continuos(char *content);
int	is_rect(char *content);

int	check_content(char *content)
{
	char	*tmp;

	tmp = content;
	content = ft_strtrim(content, "\n");
	free(tmp);
	if (!content)
		return (0);
	if (!is_all_valid(content, VALID_CHAR_SET))
		return (0);
	if (!has_all_char(content))
		return (0);
	if (!is_continuos(content))
		return (0);
	if (!is_rect(content))
		return (0);
	return (1);
}

/*
char	*get_content(int fd);

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
		ft_putstr_fd(content, 1);
		ft_putnbr_fd(check_content(content), 1);
		return (1);
	}
	else
	{
		ft_putstr_fd("Insert only 1 argument!\n", 1);
		return (0);
	}
}
*/
