/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:12:13 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/17 00:09:45 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->art.qtcollect = 0;
	game->art.s_pos = 0;
	game->art.animate = 0;
	game->stalker.qthero = 0;
	game->stalker.s_pos = 0;
	game->stalker.animate = 0;
	game->mutant.s_pos = 0;
	game->mutant.anim = 0;
	game->mutant.qtd = 0;
	game->mutant.drct = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(ERROR_DEF "Invalid parameters!\n"), 0);
	game.mapf = argv[1];
	check_extension(&game);
	load_map(&game);
	read_map(&game);
	init_game(&game);
	level_validation(&game);
	check_surrounded(&game);
	load_files(&game);
	game.vrs.mlx = mlx_init();
	load_textures(&game);
	game.vrs.mapw = game.col * game.tree.img_wid;
	game.vrs.maph = game.lin * game.tree.img_hght;
	game.vrs.win = mlx_new_window(game.vrs.mlx,
			game.vrs.mapw, game.vrs.maph, "SO_LONG");
	mlx_loop_hook(game.vrs.mlx, animate_game, &game);
	image_to_window(&game);
	mlx_key_hook(game.vrs.win, key_hook, &game);
	mlx_hook(game.vrs.win, 0, 1, key_hook, &game);
	mlx_expose_hook(game.vrs.win, image_to_window, &game);
	mlx_loop(game.vrs.mlx);
	return (0);
}
