/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:20:20 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:02:23 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Определяем положение объектов на карте

int	images_letters(t_game *game, int size, int column, int line)
{	
	if (game->map[size] == '0')
		put_ground(game, column, line);
	if (game->map[size] == '1')
		put_tree(game, column, line);
	if (game->map[size] == 'P')
		put_stalker(game, column, line);
	if (game->map[size] == 'C')
		put_artefact(game, column, line);
	if (game->map[size] == 'E')
		put_bunker(game, column, line);
	return (1);
}

// Загружаем объекты в окна

int	image_to_window(t_game *game)
{
	int		line;
	int		column;
	int		totalsize;

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
	return (0);
}
