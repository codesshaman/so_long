/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:21:31 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:53:22 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_files(t_game *game)
{
	game->stalker.path = STALKER;
	game->ground.path = GROUND;
	game->wall.path = TREE;
	game->ext.path = BUNKER;
	game->clct.path = MEDUSA;
	return (0);
}

int	finished(t_game *game)
{
	printf(WINMSG "%d\n", game->scr.scr);
	return (endgame(game), 0);
}

int	load_sprites(t_game *game)
{
	game->stalker.img = mlx_xpm_file_to_image(game->vrs.mlx, game->stalker.path,
			&game->stalker.img_wid, &game->stalker.img_hght);
	game->wall.img = mlx_xpm_file_to_image(game->vrs.mlx, game->wall.path,
			&game->wall.img_wid, &game->wall.img_hght);
	game->ground.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ground.path,
			&game->ground.img_wid, &game->ground.img_hght);
	game->clct.img = mlx_xpm_file_to_image(game->vrs.mlx, game->clct.path,
			&game->clct.img_wid, &game->clct.img_hght);
	game->ext.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ext.path,
			&game->ext.img_wid, &game->ext.img_hght);
	return (0);
}

int	unload_sprites(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->stalker.img);
	mlx_destroy_image(game->vrs.mlx, game->ground.img);
	mlx_destroy_image(game->vrs.mlx, game->wall.img);
	mlx_destroy_image(game->vrs.mlx, game->clct.img);
	mlx_destroy_image(game->vrs.mlx, game->ext.img);
	return (0);
}

int	endgame(t_game *game)
{
	unload_sprites(game);
	mlx_destroy_window(game->vrs.mlx, game->vrs.win);
	mlx_destroy_display(game->vrs.mlx);
	free(game->vrs.mlx);
	free(game->map);
	exit(0);
	return (0);
}
