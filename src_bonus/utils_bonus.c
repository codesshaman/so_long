/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:21:01 by jleslee           #+#    #+#             */
/*   Updated: 2022/01/16 14:27:16 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Измеряем длинну числа

// static int	ft_intlen(int n)
// {
// 	int		len;

// 	len = 0;
// 	if (n <= 0)
// 		len++;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// Переводим число в строку

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	long	n_value;
// 	int		i;

// 	n_value = n;
// 	i = ft_intlen(n);
// 	str = malloc(i + 1);
// 	if (!str)
// 		return (NULL);
// 	str[i--] = '\0';
// 	if (n_value == 0)
// 		str[i] = '0';
// 	while (n_value > 0)
// 	{
// 		str[i--] = n_value % 10 + '0';
// 		n_value /= 10;
// 	}
// 	return (str);
// }

// Подсчитываем длинну строки

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// Заполняем ячейки памяти символом

// static void	*ft_memset(void *str, int c, size_t n)
// {
// 	unsigned char	*p_str;

// 	p_str = str;
// 	while (n > 0)
// 	{
// 		*p_str = c;
// 		p_str++;
// 		n--;
// 	}
// 	return (str);
// }



// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(nmemb * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_memset(ptr, 0, nmemb * size);
// 	return (ptr);
// }
