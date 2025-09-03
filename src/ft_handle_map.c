/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:59 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:01 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_move(int new_x, int new_y, t_game *game)
{
	if (is_valid_move(new_x, new_y, game))
	{
		if (game->map[new_x][new_y] == 'C')
		{
			game->total_coin--;
			game->map[new_x][new_y] = '0';
		}
		if (game->map[new_x][new_y] == 'E' && game->total_coin == 0)
			ft_cleanup(game);
		game->player_x = new_x;
		game->player_y = new_y;
		game->move_count++;
		return (true);
	}
	return (false);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				mlx_image_to_window(game->mlx, game->image->tile_wall,
					y * T_S, x * T_S);
			else if (game->map[x][y] == 'C' && game->total_coin != 0)
				mlx_image_to_window(game->mlx, game->image->tile_coin,
					y * T_S, x * T_S);
			else if (game->map[x][y] == 'E' && game->total_coin == 0)
				mlx_image_to_window(game->mlx, game->image->tile_exit,
					y * T_S, x * T_S);
			else
				mlx_image_to_window(game->mlx, game->image->tile_path,
					y * T_S, x * T_S);
			y++;
		}
		x++;
	}
}
