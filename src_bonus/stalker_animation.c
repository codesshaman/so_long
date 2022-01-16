/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:26:47 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:53:33 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Движение героя

static int	animate_hero(t_game *game)
{
	if (game->stalker.animate > 30000)
	{
		unload_textures(game);
		load_textures(game);
		image_to_window(game);
		game->stalker.s_pos++;
		if (game->stalker.s_pos == 2)
			game->stalker.s_pos = 0;
		game->stalker.animate = 0;
	}
	return (0);
}

// Движение артефактов

static int	animate_artefacts(t_game *game)
{
	if (game->art.animate > 8000)
	{
		unload_textures(game);
		load_textures(game);
		image_to_window(game);
		game->art.s_pos++;
		game->mutant.s_pos++;
		if (game->art.s_pos == 4)
			game->art.s_pos = 0;
		if (game->mutant.s_pos == 3)
			game->mutant.s_pos = 0;
		game->art.animate = 0;
	}
	if (game->mutant.anim > 15000)
		game->mutant.anim = 0;
	return (0);
}

// Сталкер собирает артефакты

int	animate_char(t_game *game)
{
	animate_hero(game);
	animate_artefacts(game);
	game->stalker.animate++;
	game->art.animate++;
	game->mutant.anim++;
	return (0);
}

// Всё вместе

int	animate_game(t_game *game)
{
	animate_char(game);
	mutant_patrol(game);
	return (0);
}
