/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:08 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 16:02:59 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Загружаем карту

int	load_map(t_game *game)
{
	int		fd;
	int		eof;
	char	*map;

	eof = 1;
	game->lin = 1;
	game->flsz = 0;
	fd = open(game->mapf, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Invalid file descriptor!\n"), exit(0), 0);
	while (eof > 0)
	{
		map = calloc(1, 1);
		eof = read(fd, map, 1);
		if (*map == '\n')
			game->lin++;
		game->flsz++;
		free (map);
	}
	game->col = (game->flsz - game->lin) / game->lin;
	game->flsz--;
	game->map = malloc(game->flsz);
	close(fd);
	return (0);
}

// Читаем карту

int	read_map(t_game *game)
{
	int		fd;

	fd = open(game->mapf, O_RDONLY);
	read(fd, game->map, game->flsz);
	close(fd);
	return (0);
}

// Проверка окон

int	check_win_condition(t_game *game)
{
	if (game->art.qtcollect == 0)
	{
		printf("You can now leave the map!\n");
		game->art.qtcollect = -1;
	}
	return (0);
}

// Проверка объектов на карте

int	check_extension(t_game *game)
{
	int	size;

	size = ft_strlen(game->mapf) - 4;
	if (game->mapf[size] == '.' && game->mapf[size + 1] == 'b'
		&& game->mapf[size + 2] == 'e' && game->mapf[size + 3] == 'r')
		return (0);
	return (printf("Invalid extension. Must be a \".ber\" file\n"),
		exit(0), 0);
}
