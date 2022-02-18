/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:03:51 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/18 15:13:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/libftprintf.h"

# include <mlx.h>
# include <fcntl.h>

# define U 32 
# define BUFF_SIZE 4096 

# define DESTROY_EVENT 17
# define KEYPRESS_EVENT 2
# define KEYPRESS_MASK 1

# define ESC_KEYCODE 53
# define UP_KEYCODE 13
# define DOWN_KEYCODE 1
# define LEFT_KEYCODE 0
# define RIGHT_KEYCODE 2

# define VALID_CHAR_SET	"01CPE"

# define REL_PATH_WALL "img/Bush-4.xpm"
# define REL_PATH_COLLECTIBLE "img/Apple.xpm"
# define REL_PATH_PLAYER "img/Beer.xpm"
# define REL_PATH_EXIT "img/Chest.xpm"
# define REL_PATH_BACKGROUND "img/grass.xpm"

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
	T_WALL = 0,
	T_COLLECTIBLE,
	T_PLAYER,
	T_EXIT,
	T_BACKGROUND,
	END_ROW
}t_tile_type;

typedef struct s_tiles {
	void	*img[5];
}	t_tiles;

typedef struct s_pos {
	int	row;
	int	col;
}	t_pos;

typedef struct s_player {
	t_pos	pos;
	int		n_collectibles;
	int		moves;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_tile_type	**map;
	t_player	player;
	t_tiles		tiles;
}	t_game;

t_game		pre_setup(void);
int			free_and_exit(t_game *game);
int			get_win_row(void **map);
int			get_win_col(t_tile_type **map);
t_tile_type	**init_map(char	*fname);
t_tiles		get_tiles(t_game *game);
int			init_game(char *fname, t_game *game);
int			check_map(char **map);
char		*get_content(int fd);
int			check_content(char *content);
void		*free_split(void **av);
int			render_map(t_game game);
int			keypress_handler(int keycode, t_game *game);

#endif
