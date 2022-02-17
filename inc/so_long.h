/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:03:51 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/17 11:50:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

# include <mlx.h>
# include <fcntl.h>

# define U 16 
# define BUFF_SIZE 4096 

# define VALID_CHAR_SET	"01CPE"

# define REL_PATH_WALL "img/Bush-4.xpm"
# define REL_PATH_COLLECTIBLE "img/Apple.xpm"
# define REL_PATH_PLAYER "img/Beer.xpm"
# define REL_PATH_EXIT "img/Chest.xpm"

enum e_char
{
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
};

typedef struct s_count_char {
	int	player;
	int	collectible;
	int	exit;
}	t_count_char;	

typedef enum e_tile_type {
	T_WALL = 1,
	T_COLLECTIBLE,
	T_PLAYER,
	T_EXIT,
}t_tile_type;

typedef struct s_tiles {
	void	*img[4];
}	t_tiles;

typedef struct s_player {
	int	row;
	int	col;
	int	n_collectibles;
	int	moves;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_tile_type	**map;
	int			win_dim[2];
	t_player	player;
	t_tiles		tiles;
}	t_game;

void	pre_setup(t_game *game);
int		*get_win_dim(char **map);
int		check_map(char **map);
char	*get_content(int fd);
int		check_content(char *content);
void	*free_split(void **av);

#endif
