/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:25:59 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:36:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Проверка цветов

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Расстановка объектов на карте

int	images_letters(t_game *game, int size, int column, int line)
{	
	if (game->map[size] == '0')
		put_floor(game, column, line);
	if (game->map[size] == '1')
		put_tree(game, column, line);
	if (game->map[size] == 'P')
		put_player(game, column, line);
	if (game->map[size] == 'C')
		put_collectible(game, column, line);
	if (game->map[size] == 'E')
		put_exit(game, column, line);
	if (game->map[size] == 'X')
		put_enemy(game, column, line);
	return (1);
}

// Загрузка объектов в окна

int	image_to_window(t_game *game)
{
	int		line;
	int		column;
	int		totalsize;
	char	*score;

	totalsize = 0;
	line = 0;
	column = 0;
	while (totalsize < game->flsz)
	{
		column += images_letters(game, totalsize, column, line);
		if (game->map[totalsize++] == '\n')
		{
			column = 0;
			line++;
		}
	}
	check_win_condition(game);
	score = ft_itoa(game->scr.scr);
	mlx_string_put(game->vrs.mlx, game->vrs.win, (game->vrs.mapw / 2 - 50),
		25, create_trgb(0, 255, 255, 255), "SCORE: ");
	mlx_string_put(game->vrs.mlx, game->vrs.win, (game->vrs.mapw / 2),
		25, create_trgb(0, 255, 255, 255), score);
	free(score);
	return (0);
}
