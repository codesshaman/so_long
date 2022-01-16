/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_objects_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:21:41 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:31:41 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Загрузка текстур

int	load_files(t_game *game)
{
	game->hero.path[HERO_UP] = STALKER;
	game->hero.path[HERO_STILL] = STALKER2;
	game->floor.path = GROUND;
	game->wall.path = TREE;
	game->ext.path = BUNKER;
	game->clct.path[COLLECT_FRONT] = MEDUSA1;
	game->clct.path[COLLECT_LEFT] = MEDUSA2;
	game->clct.path[COLLECT_SIDE] = MEDUSA3;
	game->clct.path[COLLECT_RIGHT] = MEDUSA4;
	game->enemy.path[ENEMY_F1] = MUTANT1;
	game->enemy.path[ENEMY_F2] = MUTANT2;
	game->enemy.path[ENEMY_F3] = MUTANT3;
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
	game->hero.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->hero.path[game->hero.s_pos],
			&game->hero.img_wid, &game->hero.img_hght);
	game->wall.img = mlx_xpm_file_to_image(game->vrs.mlx, game->wall.path,
			&game->wall.img_wid, &game->wall.img_hght);
	game->floor.img = mlx_xpm_file_to_image(game->vrs.mlx, game->floor.path,
			&game->floor.img_wid, &game->floor.img_hght);
	game->clct.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->clct.path[game->clct.s_pos], &game->clct.img_wid,
			&game->clct.img_hght);
	game->ext.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ext.path,
			&game->ext.img_wid, &game->ext.img_hght);
	game->enemy.img = mlx_xpm_file_to_image(game->vrs.mlx,
			game->enemy.path[game->enemy.s_pos],
			&game->ext.img_wid, &game->ext.img_hght);
	return (0);
}

// Выгрузка текстур

int	unload_textures(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->hero.img);
	mlx_destroy_image(game->vrs.mlx, game->floor.img);
	mlx_destroy_image(game->vrs.mlx, game->wall.img);
	mlx_destroy_image(game->vrs.mlx, game->clct.img);
	mlx_destroy_image(game->vrs.mlx, game->ext.img);
	mlx_destroy_image(game->vrs.mlx, game->enemy.img);
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
