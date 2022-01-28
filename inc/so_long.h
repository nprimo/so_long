/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:59 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/28 16:42:15 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*adr;
	int		bpp;
	int		ll;
	int		end;
}				t_data;

#endif
