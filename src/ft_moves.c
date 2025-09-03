/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:46 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:48 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_down(t_game *game, int new_x, int new_y, int direction)
{
	direction = 1;
	new_x++;
	if (ft_check_move(new_x, new_y, game))
	{
		printf("move count: %d\n", game->move_count);
		return (direction);
	}
	return (-1);
}

int	ft_move_up(t_game *game, int new_x, int new_y, int direction)
{
	direction = 0;
	new_x--;
	if (ft_check_move(new_x, new_y, game))
	{
		ft_printf("move count: %d\n", game->move_count);
		return (direction);
	}
	return (-1);
}

int	ft_move_left(t_game *game, int new_x, int new_y, int direction)
{
	direction = 2;
	new_y--;
	if (ft_check_move(new_x, new_y, game))
	{
		printf("move count: %d\n", game->move_count);
		return (direction);
	}
	return (-1);
}

int	ft_move_right(t_game *game, int new_x, int new_y, int direction)
{
	direction = 3;
	new_y++;
	if (ft_check_move(new_x, new_y, game))
	{
		printf("move count: %d\n", game->move_count);
		return (direction);
	}
	return (-1);
}

int	handle_movement(t_game *game, mlx_key_data_t keydata)
{
	int	direction;
	int	new_x;
	int	new_y;

	direction = -1;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		direction = ft_move_up(game, new_x, new_y, direction);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		direction = ft_move_down(game, new_x, new_y, direction);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		direction = ft_move_left(game, new_x, new_y, direction);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		direction = ft_move_right(game, new_x, new_y, direction);
	return (direction);
}
