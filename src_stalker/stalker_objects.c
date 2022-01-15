/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:15:07 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/15 13:48:59 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// рисуем сталкера

int	put_stalker(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->stalker.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// рисуем дерево

int	put_tree(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->tree.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// рисуем землю

int	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// рисуем артефакт

int	put_artefact(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->arts.img, (x * game->tree.img_wid + 12),
		(y * game->tree.img_hght + 12));
	return (0);
}

// рисуем бункер

int	put_bunker(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->bunker.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}
