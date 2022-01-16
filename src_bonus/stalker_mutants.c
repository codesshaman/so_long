/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_mutants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:30:33 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:37:11 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Загружаем мутанта

int	put_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->enemy.img, (x * game->tree.img_wid),
		(y * game->tree.img_hght));
	return (0);
}

// Проверяем позицию мутанта на карте

static void	check_positions(t_game *game, char **nextpos)
{
	int	i;

	game->enemy.chk = 0;
	i = 0;
	while (i < game->enemy.qtd)
	{
		if (*nextpos[i] == '1' || *nextpos[i] == 'C')
			game->enemy.chk++ ;
		i++;
	}
	if (game->enemy.chk == game->enemy.qtd)
		game->enemy.drct *= -1;
}

// Получаем позицию мутанта

char	**getenemypositions(t_game *game)
{
	int		i;
	char	*currentpos;
	char	**enemies;

	enemies = malloc(game->enemy.qtd * 2 * sizeof(int));
	currentpos = get_player(game->map, 'X');
	i = 0;
	while (i < game->enemy.qtd)
	{
		if (i == 0)
		{
			enemies[i] = get_player(currentpos, 'X');
			currentpos = enemies[i];
		}
		else
		{
			enemies[i] = get_player(currentpos + 1, 'X');
			currentpos = enemies[i];
		}
		i++;
	}
	return (enemies);
}

// Задаём движение мутанта по карте

int	enemy_patrol(t_game *game)
{
	char	**enep;
	char	**nxtp;
	int		i;

	i = -1;
	enep = getenemypositions(game);
	nxtp = malloc(game->enemy.qtd * 2 * sizeof(int));
	while (++i < game->enemy.qtd)
	{
		nxtp[i] = enep[i] + (game->col * game->enemy.drct)
			+ game->enemy.drct;
		if ((*nxtp[i] == '0' || *nxtp[i] == 'P')
			&& game->enemy.anim > 15000)
		{
			if (*nxtp[i] == 'P' && game->enemy.anim > 8000)
			{
				game->hero.qthero = -1;
				return (endgame(game), 1);
			}
			*enep[i] = '0';
			*nxtp[i] = 'X';
		}
		enep[i] = nxtp[i];
	}
	return (check_positions(game, nxtp), free(nxtp), free(enep), 0);
}
