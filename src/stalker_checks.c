/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:38:12 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/13 21:20:14 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Проверка расширения карты

int	extension_check(t_game *game)
{
	int	size;

	size = ft_strlen(game->mappath) - 4;
	if (game->mappath[size] == '.' && game->mappath[size + 1] == 'b'
		&& game->mappath[size + 2] == 'e' && game->mappath[size + 3] == 'r')
		return (0);
	return (printf("Invalid extension. Must be a \".ber\" file\n"),
		exit(0), 0);
}