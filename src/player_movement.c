/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:11:21 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:21:03 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	move_up(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') - game->col - 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->medusa.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->medusa.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_down(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') + game->col + 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->medusa.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->medusa.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_left(t_game *game)
{
	char	*playercurrentpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P') - 1;
		if (playercurrentpos [0] == '0' || playercurrentpos[0] == 'C'
			|| (playercurrentpos[0] == 'E' && game->medusa.qtcollect == -1))
		{
			if (playercurrentpos[0] == 'C')
				game->medusa.qtcollect--;
			if (playercurrentpos[0] == 'E')
				finished(game);
			playercurrentpos[1] = '0';
			playercurrentpos[0] = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_right(t_game *game)
{
	char	*playercurrentpos;

	if (game->stalker.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		if (playercurrentpos [1] == '0' || playercurrentpos[1] == 'C'
			|| (playercurrentpos[1] == 'E' && game->medusa.qtcollect == -1))
		{
			if (playercurrentpos[1] == 'C')
				game->medusa.qtcollect--;
			if (playercurrentpos[1] == 'E')
				finished(game);
			playercurrentpos[0] = '0';
			playercurrentpos[1] = 'P';
			game->scr.scr++;
		}
	}		
	return (0);
}
