/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:59 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/04 11:51:45 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

# include <mlx.h>
# include <fcntl.h>

# define U 50
# define BUFF_SIZE 4096 

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_point	pos;
}	t_vars;

typedef struct s_data {
	void	*img;
	char	*adr;
	int		bpp;
	int		ll;
	int		end;
}	t_data;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_app(int keycode, t_vars *vars);
char	**get_map(int fd);
int		*get_dim(char **map);

// Check maps functions
int		is_rect(char **map);
int		is_closed(char **map);
int		is_valid_map(char **map);

#endif
