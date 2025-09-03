/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:50 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/22 12:19:43 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_itens(char **map, int rows, int cols)
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
			if (map[i][j] == 'C' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	find_p(t_point *p, int rows, int cols, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
			{
				p->row = i;
				p->col = j;
			}
			j++;
		}
		i++;
	}
}

int	check_square(char **map, int rows)
{
	int	i;
	int	size_l;
	int	size_l_n;

	i = 0;
	size_l = ft_strlen(map[i]);
	while (++i < rows)
	{
		size_l_n = ft_strlen(map[i]);
		if (size_l != size_l_n)
			return (2);
	}
	return (0);
}

int	check_corner(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		if (map[i][j] != '1' || map[i][cols - 1] != '1')
			return (4);
		while (j < cols)
		{
			if (i == 0 || i == rows - 1)
			{
				if (map[i][j] != '1')
					return (4);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checker(char **map, int rows, int cols)
{
	int	ch;

	ch = 0;
	ch = check_empty(map, rows);
	if (ch == 1)
		return (ft_printf("Error\nempty file"), 1);
	ch = check_square(map, rows);
	if (ch == 2)
		return (ft_printf("Error\nnot a square"), 1);
	ch = check_letters(map, rows, cols);
	if (ch == 3)
		return (ft_printf("Error\nentities error"), 1);
	ch = check_corner(map, rows, cols);
	if (ch == 4)
		return (ft_printf("Error\nmissing walls around the map"), 1);
	ch = flood_map(map, rows, cols);
	if (ch == 5)
		return (ft_printf("Error\nno valid path"), 1);
	return (ch);
}
