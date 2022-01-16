/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:26:47 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:32:42 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Движение героя

static int	animate_hero(t_game *game)
{
	if (game->hero.animate > 30000)
	{
		unload_textures(game);
		load_textures(game);
		image_to_window(game);
		game->hero.s_pos++;
		if (game->hero.s_pos == 2)
			game->hero.s_pos = 0;
		game->hero.animate = 0;
	}
	return (0);
}

// Движение монстров

static int	animate_clct(t_game *game)
{
	if (game->clct.animate > 8000)
	{
		unload_textures(game);
		load_textures(game);
		image_to_window(game);
		game->clct.s_pos++;
		game->enemy.s_pos++;
		if (game->clct.s_pos == 4)
			game->clct.s_pos = 0;
		if (game->enemy.s_pos == 3)
			game->enemy.s_pos = 0;
		game->clct.animate = 0;
	}
	if (game->enemy.anim > 15000)
		game->enemy.anim = 0;
	return (0);
}

// Анимация героя в движении

int	animate_char(t_game *game)
{
	animate_hero(game);
	animate_clct(game);
	game->hero.animate++;
	game->clct.animate++;
	game->enemy.anim++;
	return (0);
}

// Всё вместе

int	animate_game(t_game *game)
{
	animate_char(game);
	enemy_patrol(game);
	return (0);
}
