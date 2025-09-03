/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:16 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:18 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_move(int new_x, int new_y, t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = ft_strlen(game->map[0]);
	while (game->map[rows])
		rows++;
	if (new_y < 0 || new_y >= cols || new_x < 0 || new_x >= rows)
		return (false);
	if (game->map[new_x][new_y] == '1')
		return (false);
	return (true);
}

void	update_player_image(t_game *game, int direction)
{
	if (direction == 0)
		game->image->ship = mlx_texture_to_image(game->mlx,
				game->txt->sprite_up);
	else if (direction == 1)
		game->image->ship = mlx_texture_to_image(game->mlx,
				game->txt->sp_d);
	else if (direction == 2)
		game->image->ship = mlx_texture_to_image(game->mlx,
				game->txt->sprite_left);
	else if (direction == 3)
		game->image->ship = mlx_texture_to_image(game->mlx,
				game->txt->sprite_right);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		direction;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_cleanup(game);
	direction = handle_movement(game, keydata);
	if (direction != -1)
	{
		update_player_image(game, direction);
		draw_map(game);
		mlx_image_to_window(game->mlx, game->image->ship,
			game->player_y * T_S, game->player_x * T_S);
	}
}
