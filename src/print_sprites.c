/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:15:07 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:21:23 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_tree(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->tree.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

int	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->stalker.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

int	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ground.img, (x * game->tree.img_wid),
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
