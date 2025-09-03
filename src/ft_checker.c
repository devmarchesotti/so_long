/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:11:19 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:11:25 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_empty(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] == '\0' || map[i][0] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_e(char **map, int rows, int cols)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_c(char **map, int rows, int cols)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_p(char **map, int rows, int cols)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_letters(char **map, int rows, int cols)
{
	int	c;
	int	p;
	int	e;

	c = check_c(map, rows, cols);
	p = check_p(map, rows, cols);
	e = check_e(map, rows, cols);
	if (c >= 1 && p == 1 && e == 1)
		return (0);
	return (3);
}
