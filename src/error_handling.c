/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:49:26 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:19:45 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	frst_lst_line(t_game *game, int line, int col)
{
	if (line == 0)
		while (++col < game->col)
			if (game->map[col] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	if (line == game->lin)
	{
		col = ((game->flsz - 1) - (game->col - 1));
		while (++col < game->flsz)
			if (game->map[col] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	}
	return (0);
}

int	check_walling(t_game *game)
{
	int	c;
	int	l;

	l = 0;
	while (l <= game->lin)
	{
		c = -1;
		frst_lst_line(game, l, c);
		if (l == 1)
			if (game->map[game->col + l] != '1'
				|| game->map[game->col * 2] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		if (l > 0 && l < game->lin)
			if (game->map[((game->col + 1) * l)] != '1'
				|| game->map[game->col - 1 + ((game->col + 1) * (l))] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		l++;
	}
	return (0);
}

static int	check_invalid_chars(t_game *game, int pos)
{
	char	*valid_chars;

	valid_chars = "PEC10\n";
	if (get_player(valid_chars, game->map[pos]) == NULL)
		return (printf(ERROR_DEF PARAMERROR), free(game->map), exit(0), 0);
	else
		return (0);
}

static int	check_map_content(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->flsz - 1)
	{
		check_invalid_chars(game, i);
		if (game->map[i] == 'P')
			game->stalker.qthero++;
		if (game->map[i] == 'E')
			game->qtext++;
		if (game->map[i] == 'C')
			game->medusa.qtcollect++;
		i++;
	}
	return (0);
}

int	level_validation(t_game *game)
{
	check_map_content(game);
	if (game->stalker.qthero == 0)
		return (printf(ERROR_DEF OPLRERROR), free(game->map), exit(0), 0);
	if (game->stalker.qthero > 1)
		return (printf(ERROR_DEF MRPLRERROR), free(game->map), exit(0), 0);
	if (game->medusa.qtcollect == 0)
		return (printf(ERROR_DEF ARTERROR), free(game->map), exit(0), 0);
	if (game->qtext == 0)
		return (printf(ERROR_DEF EXTERROR), free(game->map), exit(0), 0);
	return (0);
}
