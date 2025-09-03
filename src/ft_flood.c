/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:41 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:12:48 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, int x, int y, t_point *char_pos)
{
	if (x < 0 || y < 0 || x >= char_pos->max_rows || y >= char_pos->max_cols)
		return ;
	if (tab[x][y] != '0' && tab[x][y] != 'E' && tab[x][y] != 'C')
		return ;
	if (tab[x][y] == 'C' || tab[x][y] == 'E')
		char_pos->n_collect += 1;
	tab[x][y] = 'F';
	flood_fill(tab, x + 1, y, char_pos);
	flood_fill(tab, x - 1, y, char_pos);
	flood_fill(tab, x, y + 1, char_pos);
	flood_fill(tab, x, y - 1, char_pos);
}

char	**make_area(char **a, int rows, int cols)
{
	char	**res;
	int		i;
	int		j;

	res = ft_calloc(sizeof(char *), rows + 1);
	i = 0;
	while (i < rows)
	{
		res[i] = ft_calloc(sizeof(char *), cols + 1);
		j = 0;
		while (j < cols)
		{
			res[i][j] = a[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

t_point	*create_p(int rows, int cols, char **map)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	if (p)
	{
		p->max_rows = rows;
		p->max_cols = cols;
		p->n_collect = 0;
		find_p(p, rows, cols, map);
	}
	return (p);
}

int	cleanup(t_point *char_pos, char **map)
{
	if (char_pos)
		free(char_pos);
	if (map)
		ft_free(map);
	return (1);
}

int	flood_map(char **map, int rows, int cols)
{
	t_point	*char_pos;
	char	**area;
	int		check;

	check = count_itens(map, rows, cols);
	char_pos = create_p(rows, cols, map);
	area = make_area(map, rows, cols);
	area[char_pos->row][char_pos->col] = '0';
	flood_fill(area, char_pos->row, char_pos->col, char_pos);
	if (char_pos->n_collect != check)
	{
		cleanup(char_pos, area);
		return (5);
	}
	cleanup(char_pos, area);
	return (0);
}
