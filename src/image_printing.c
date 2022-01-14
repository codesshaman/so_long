/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:20:20 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:20:40 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	imgtoPrint(t_game *game, int size, int column, int line)
{	
	if (game->map[size] == '0')
		put_ground(game, column, line);
	if (game->map[size] == '1')
		put_tree(game, column, line);
	if (game->map[size] == 'P')
		put_player(game, column, line);
	if (game->map[size] == 'C')
		put_collectible(game, column, line);
	if (game->map[size] == 'E')
		put_exit(game, column, line);
	return (1);
}

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
		column += imgtoPrint(game, totalsize, column, line);
		if (game->map[totalsize++] == '\n')
		{
			column = 0;
			line++;
		}
	}
	check_win_condition(game);
	return (0);
}
