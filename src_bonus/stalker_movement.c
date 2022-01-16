/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:25:27 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 15:54:23 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Получение текущей позиции игрока

char	*get_player(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// Сдвиг игрока вверх

int	move_up(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') - game->col - 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->art.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->art.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

// Сдвиг игрока вниз

int	move_down(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') + game->col + 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->art.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->art.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

// Сдвиг игрока влево

int	move_left(t_game *game)
{
	char	*playercurrentpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P') - 1;
		if (playercurrentpos [0] == '0' || playercurrentpos[0] == 'C'
			|| (playercurrentpos[0] == 'E' && game->art.qtcollect == -1))
		{
			if (playercurrentpos[0] == 'C')
				game->art.qtcollect--;
			if (playercurrentpos[0] == 'E')
				finished(game);
			playercurrentpos[1] = '0';
			playercurrentpos[0] = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

// Сдвиг игрока вправо

int	move_right(t_game *game)
{
	char	*playercurrentpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		if (playercurrentpos [1] == '0' || playercurrentpos[1] == 'C'
			|| (playercurrentpos[1] == 'E' && game->art.qtcollect == -1))
		{
			if (playercurrentpos[1] == 'C')
				game->art.qtcollect--;
			if (playercurrentpos[1] == 'E')
				finished(game);
			playercurrentpos[0] = '0';
			playercurrentpos[1] = 'P';
			game->scr.scr++;
		}
	}		
	return (0);
}
