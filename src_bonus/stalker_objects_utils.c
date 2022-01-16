/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_objects_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:21:41 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:55:10 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Загрузка текстур

int	load_files(t_game *game)
{
	game->stalker.path[HERO_UP] = STALKER;
	game->stalker.path[HERO_STILL] = STALKER2;
	game->floor.path = GROUND;
	game->tree.path = TREE;
	game->bunker.path = BUNKER;
	game->art.path[COLLECT_FRONT] = MEDUSA1;
	game->art.path[COLLECT_LEFT] = MEDUSA2;
	game->art.path[COLLECT_SIDE] = MEDUSA3;
	game->art.path[COLLECT_RIGHT] = MEDUSA4;
	game->mutant.path[ENEMY_F1] = MUTANT1;
	game->mutant.path[ENEMY_F2] = MUTANT2;
	game->mutant.path[ENEMY_F3] = MUTANT3;
	return (0);
}

// Окончание игры

int	finished(t_game *game)
{
	printf(WINMSG "%d\n", game->scr.scr);
	return (endgame(game), 1);
}

// Загрузка текстур

int	load_textures(t_game *game)
{
	game->stalker.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->stalker.path[game->stalker.s_pos],
			&game->stalker.img_wid, &game->stalker.img_hght);
	game->tree.img = mlx_xpm_file_to_image(game->vrs.mlx, game->tree.path,
			&game->tree.img_wid, &game->tree.img_hght);
	game->floor.img = mlx_xpm_file_to_image(game->vrs.mlx, game->floor.path,
			&game->floor.img_wid, &game->floor.img_hght);
	game->art.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->art.path[game->art.s_pos], &game->art.img_wid,
			&game->art.img_hght);
	game->bunker.img = mlx_xpm_file_to_image(game->vrs.mlx, game->bunker.path,
			&game->bunker.img_wid, &game->bunker.img_hght);
	game->mutant.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->mutant.path[game->mutant.s_pos],
			&game->bunker.img_wid, &game->bunker.img_hght);
	return (0);
}

// Выгрузка текстур

int	unload_textures(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->stalker.img);
	mlx_destroy_image(game->vrs.mlx, game->floor.img);
	mlx_destroy_image(game->vrs.mlx, game->tree.img);
	mlx_destroy_image(game->vrs.mlx, game->art.img);
	mlx_destroy_image(game->vrs.mlx, game->bunker.img);
	mlx_destroy_image(game->vrs.mlx, game->mutant.img);
	return (0);
}

// Выход из игры

int	endgame(t_game *game)
{
	unload_textures(game);
	mlx_destroy_window(game->vrs.mlx, game->vrs.win);
	mlx_destroy_display(game->vrs.mlx);
	free(game->vrs.mlx);
	free(game->map);
	exit(0);
	return (0);
}
