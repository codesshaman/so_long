/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:42:32 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:38:42 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_tree(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->tree.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

int	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->hero.img, (x * game->tree.img_wid + 5),
		(y * game->tree.img_hght));
	return (0);
}

int	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->clct.img, (x * game->tree.img_wid + 12),
		(y * game->tree.img_hght + 12));
	return (0);
}

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ext.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}
