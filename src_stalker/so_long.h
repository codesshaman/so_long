/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:16:23 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/15 19:30:07 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"

# define W         119 
# define S       115
# define A       97
# define D      100

# define ESC        65307

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define ERROR_DEF  "Error\n"
# define OPLRERROR  "Need a stalker on the map!\n"
# define MRPLRERROR "Only one stalker allowed!\n"
# define ARTERROR	"Need at least one artefact!\n"
# define EXTERROR   "Need at least one exit!\n"
# define VLDMERROR  "Not a valid map!\n"
# define PARAMERROR	"Invalid parameter!\n"
# define WALL_ERR   "Map should be surrounded by forest!\n"
# define SQREERROR	"Map cannot be a square\n"
# define WINMSG		"You Won! Score: "
# define LOSEMSG	"You Lost!\nFINAL SCORE: "
# define LEAVE		"You may now close the game.\n"

# define STALKER	"./textures/stalker.xpm"
# define STALKER2	"./textures/stalker-alt.xpm"
# define GROUND 	"./textures/ground.xpm"
# define TREE		"./textures/tree.xpm"
# define BUNKER		"./textures/bunker.xpm"
# define MEDUSA		"./textures/medusa.xpm"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		maph;
	int		mapw;
}				t_vars;

typedef struct s_sprite{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
}				t_sprite;

typedef struct s_stalker{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
	int		qthero;
}				t_stalker;

typedef struct s_collect{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
	int		qtcollect;
}				t_collect;

typedef struct s_score{
	int		scr;
}				t_score;

typedef struct s_game{
	t_vars		vrs;
	t_score		scr;
	t_stalker	stalker;
	t_collect	arts;
	t_sprite	tree;
	t_sprite	ground;
	t_sprite	bunker;
	int			qtext;
	int			flsz;
	int			col;
	int			lin;
	char		*map;
	char		*mappath;
}				t_game;

char		*get_player(char *s, char c);
int			load_objects(t_game *game);
int			unload_objects(t_game *game);
int			load_files(t_game *game);
int			load_map(t_game *game);
int			read_map(t_game *game);
int			endgame(t_game *game);
int			put_tree(t_game *game, int x, int y);
int			put_ground(t_game *game, int x, int y);
int			put_stalker(t_game *game, int x, int y);
int			put_artefact(t_game *game, int x, int y);
int			put_bunker(t_game *game, int x, int y);
int			move_up(t_game *game);
int			move_down(t_game *game);
int			move_left(t_game *game);
int			move_right(t_game *game);
int			image_to_window(t_game *game);
int			images_letters(t_game *game, int size, int column, int line);
int			ft_strlen(char *s);
void		*ft_calloc(size_t nmemb, size_t size);
int			extension_check(t_game *game);
int			check_surrounded(t_game *game);
int			level_validation(t_game *game);
int			check_win_condition(t_game *game);
int			finished(t_game *game);

#endif