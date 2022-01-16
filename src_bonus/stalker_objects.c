/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:42:32 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 16:01:49 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Грузим сталкера

int	put_stalker(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->stalker.img, (x * game->tree.img_wid + 5),
		(y * game->tree.img_hght));
	return (0);
}

// Грузим землю, я не сойду

int	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// Грузим дерево

int	put_tree(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->tree.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// Грузим аретфакты

int	put_artefact(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->art.img, (x * game->tree.img_wid + 12),
		(y * game->tree.img_hght + 12));
	return (0);
}

// Грузим бункер Сидоровича

int	put_bunker(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->bunker.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}
