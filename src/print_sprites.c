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

int	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->wall.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->stalker.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->clct.img, (x * game->wall.img_wid + 12),
		(y * game->wall.img_hght + 12));
	return (0);
}

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ext.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}
