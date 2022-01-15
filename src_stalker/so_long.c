/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:17:59 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/15 17:54:15 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Инициализация клавиш

static int	key_hook(int keycode, t_game *game)
{
	static int	check_steps;

	check_steps = game->scr.scr;
	if (keycode == ESC)
		endgame(game);
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == D || keycode == A || keycode == W || keycode == S || \
	keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		image_to_window(game);
	if (game->scr.scr > check_steps)
		printf("Steps = %d\n", game->scr.scr);
	return (0);
}

// Инициализация игры

static int	init_game(t_game *game)
{
	game->scr.scr = 0;
	game->qtext = 0;
	game->arts.qtcollect = 0;
	game->stalker.qthero = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(ERROR_DEF "Invalid parameters!\n"), 0);
	game.mappath = argv[1];
	extension_check(&game);
	load_map(&game);
	read_map(&game);
	init_game(&game);
	level_validation(&game);
	check_surrounded(&game);
	load_files(&game);
	game.vrs.mlx = mlx_init();
	load_objects(&game);
	game.vrs.mapw = game.col * game.tree.img_wid;
	game.vrs.maph = game.lin * game.tree.img_hght;
	game.vrs.win = mlx_new_window(game.vrs.mlx,
			game.vrs.mapw, game.vrs.maph, "SO_LONG");
	image_to_window(&game);
	mlx_key_hook(game.vrs.win, key_hook, &game);
	mlx_hook(game.vrs.win, 33, 1L << 2, endgame, &game);
	mlx_expose_hook(game.vrs.win, image_to_window, &game);
	mlx_loop(game.vrs.mlx);
	return (0);
}
