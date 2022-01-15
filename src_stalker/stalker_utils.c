/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:21:31 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/15 13:50:55 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Загрузка текстур

int	load_files(t_game *game)
{
	game->stalker.path = STALKER;
	game->ground.path = GROUND;
	game->tree.path = TREE;
	game->bunker.path = BUNKER;
	game->arts.path = MEDUSA;
	return (0);
}

// Функция загрузки объектов

int	load_objects(t_game *game)
{
	game->stalker.img = mlx_xpm_file_to_image(game->vrs.mlx, game->stalker.path,
			&game->stalker.img_wid, &game->stalker.img_hght);
	game->tree.img = mlx_xpm_file_to_image(game->vrs.mlx, game->tree.path,
			&game->tree.img_wid, &game->tree.img_hght);
	game->ground.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ground.path,
			&game->ground.img_wid, &game->ground.img_hght);
	game->arts.img = mlx_xpm_file_to_image(game->vrs.mlx, game->arts.path,
			&game->arts.img_wid, &game->arts.img_hght);
	game->bunker.img = mlx_xpm_file_to_image(game->vrs.mlx, game->bunker.path,
			&game->bunker.img_wid, &game->bunker.img_hght);
	return (0);
}

// Функция выгрузки объектов

int	unload_objects(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->stalker.img);
	mlx_destroy_image(game->vrs.mlx, game->ground.img);
	mlx_destroy_image(game->vrs.mlx, game->tree.img);
	mlx_destroy_image(game->vrs.mlx, game->arts.img);
	mlx_destroy_image(game->vrs.mlx, game->bunker.img);
	return (0);
}

// Функция финиширования игрока

int	finished(t_game *game)
{
	printf(WINMSG "%d\n", game->scr.scr);
	return (endgame(game), 1);
}

// Функция выхода из игры

int	endgame(t_game *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vrs.mlx, game->vrs.win);
	mlx_destroy_display(game->vrs.mlx);
	free(game->vrs.mlx);
	free(game->map);
	exit(0);
	return (0);
}
