/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:09:52 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:20:14 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game *game)
{
	int		fd;
	int		eof;
	char	*map;

	eof = 1;
	game->lin = 1;
	game->flsz = 0;
	fd = open(game->mappath, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Invalid file descriptor!\n"), exit(0), 0);
	while (eof > 0)
	{
		map = ft_calloc(1, 1);
		eof = read(fd, map, 1);
		if (*map == '\n')
			game->lin++;
		game->flsz++;
		free (map);
	}
	game->col = (game->flsz - game->lin) / game->lin;
	game->flsz--;
	game->map = malloc(game->flsz + 1);
	close(fd);
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;

	fd = open(game->mappath, O_RDONLY);
	read(fd, game->map, game->flsz + 1);
	close(fd);
	return (0);
}

int	check_win_condition(t_game *game)
{
	if (game->medusa.qtcollect == 0)
	{
		printf("You can now leave the map!\n");
		game->medusa.qtcollect = -1;
	}
	return (0);
}
