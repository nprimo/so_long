/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:45:24 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 15:18:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_split(char **av)
{
	char	**head;
	char	*tmp;

	head = av;
	while (*head)
	{
		tmp = *head;
		free(tmp);
		head++;
	}
	free(av);
	return (NULL);
}
