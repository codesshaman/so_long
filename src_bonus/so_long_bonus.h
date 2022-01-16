/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:22:33 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 16:01:19 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
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
# define OPLRERROR  "Need a player position on the map!\n"
# define MRPLRERROR "Only 1 player allowed!\n"
# define CLCTERROR  "Need one or more artefacts!\n"
# define EXTERROR   "Need at least one exit!\n"
# define VLDMERROR  "Not a valid map!\n"
# define PARAMERROR	"Invalid parameter!\n"
# define WALL_ERR   "Map should be surrounded by trees!\n"
# define SQREERROR	"Map cannot be a square\n"

# define WINMSG		"You Win! Score: "
# define LOSEMSG	"You Lost!\nScore: "

# define STALKER	"./textures/stalker.xpm"
# define STALKER2	"./textures/stalker-alt.xpm"
# define GROUND		"./textures/ground.xpm"
# define TREE		"./textures/tree.xpm"
# define BUNKER		"./textures/bunker.xpm"
# define MEDUSA1	"./textures/medusa.xpm"
# define MEDUSA2	"./textures/medusa2.xpm"
# define MEDUSA3	"./textures/medusa3.xpm"
# define MEDUSA4	"./textures/medusa4.xpm"
# define MUTANT1	"./textures/mutant1.xpm"
# define MUTANT2	"./textures/mutant2.xpm"
# define MUTANT3	"./textures/mutant3.xpm"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		maph;
	int		mapw;
}	t_vars;

enum	e_hero {
	HERO_UP,
	HERO_STILL,
};

enum	e_collect {
	COLLECT_FRONT,
	COLLECT_LEFT,
	COLLECT_SIDE,
	COLLECT_RIGHT,
};

enum	e_enemy {
	ENEMY_F1,
	ENEMY_F2,
	ENEMY_F3,
};

typedef struct s_sprite{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
}	t_sprite;

typedef struct s_Hero{
	char	*path[2];
	void	*img;
	int		img_wid;
	int		img_hght;
	int		s_pos;
	int		qthero;
	int		animate;
}	t_hero;

typedef struct s_collect{
	char	*path[4];
	void	*img;
	int		img_wid;
	int		img_hght;
	int		s_pos;
	int		qtcollect;
	int		animate;
}	t_collect;

typedef struct s_enemy{
	char			*path[3];
	void			*img;
	char			*pos;
	int				img_wid;
	int				img_hght;
	int				s_pos;
	int				qtd;
	int				anim;
	int				chk;
	int				drct;
}	t_enemy;

typedef struct s_score{
	int		scr;
}	t_score;

typedef struct s_game{
	t_vars		vrs;
	t_score		scr;
	t_hero		stalker;
	t_enemy		mutant;
	t_collect	art;
	t_sprite	tree;
	t_sprite	floor;
	t_sprite	bunker;
	int			qtext;
	int			flsz;
	int			col;
	int			lin;
	char		*map;
	char		*mapf;
}	t_game;

char	*get_player(char *s, char c);
int		load_textures(t_game *game);
int		unload_textures(t_game *game);
int		load_files(t_game *game);
int		load_map(t_game *game);
int		read_map(t_game *game);
int		endgame(t_game *game);
int		put_tree(t_game *game, int x, int y);
int		put_ground(t_game *game, int x, int y);
int		put_stalker(t_game *game, int x, int y);
int		put_artefact(t_game *game, int x, int y);
int		put_bunker(t_game *game, int x, int y);
int		put_mutant(t_game *game, int x, int y);
int		mutant_patrol(t_game *game);
int		animate_game(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		image_to_window(t_game *game);
int		images_letters(t_game *game, int size, int column, int line);
int		check_extension(t_game *game);
int		check_surrounded(t_game *game);
int		level_validation(t_game *game);
int		check_win_condition(t_game *game);
int		finished(t_game *game);

#endif