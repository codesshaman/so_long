/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalker_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:38:12 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/15 12:15:10 by jleslee          ###   ########.fr       */
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

// Проверка длинны строки

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// Проверка количества конкретных значений в строке

static void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p_str;

	p_str = str;
	while (n > 0)
	{
		*p_str = c;
		p_str++;
		n--;
	}
	return (str);
}

// Выделяем память и заполняем её нулями

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
