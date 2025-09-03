/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:28 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:29 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*set_t_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->total_coin = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->total_coin++;
			else if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
	game->map_width = j * T_S;
	game->map_height = i * T_S;
	return (game);
}

char	**ft_load_map(char *filename)
{
	int		rows;
	int		cols;
	char	**map;

	rows = 0;
	cols = 0;
	map = ft_parse_map(filename, &rows, &cols);
	if (!map)
		return (NULL);
	return (map);
}
