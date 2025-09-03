/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:55 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:57 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_prep_text(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_texture));
	if (!game->txt)
		return ;
	game->txt->sprite_up = mlx_load_png("textures/ship_up.png");
	game->txt->sp_d = mlx_load_png("textures/ship_down.png");
	game->txt->sprite_left = mlx_load_png("textures/ship_left.png");
	game->txt->sprite_right = mlx_load_png("textures/ship_right.png");
	game->txt->coin = mlx_load_png("textures/coin.png");
	game->txt->path = mlx_load_png("textures/gras.png");
	game->txt->wall = mlx_load_png("textures/rock.png");
	game->txt->exit = mlx_load_png("textures/exit.png");
}

void	ft_prep_image(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if (!game->image)
		return ;
	game->image->ship = mlx_texture_to_image(game->mlx, game->txt->sp_d);
	game->image->tile_path = mlx_texture_to_image(game->mlx, game->txt->path);
	game->image->tile_wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->image->tile_coin = mlx_texture_to_image(game->mlx, game->txt->coin);
	game->image->tile_exit = mlx_texture_to_image(game->mlx, game->txt->exit);
}
