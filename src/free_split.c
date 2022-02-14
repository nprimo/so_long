/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:45:24 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/14 11:10:09 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_split(void **av)
{
	void	**head;
	void	*tmp;

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
