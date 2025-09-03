/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:18 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:12:27 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->ship);
	mlx_delete_image(game->mlx, game->image->tile_coin);
	mlx_delete_image(game->mlx, game->image->tile_exit);
	mlx_delete_image(game->mlx, game->image->tile_path);
	mlx_delete_image(game->mlx, game->image->tile_wall);
}

void	ft_delete_textures(t_game *game)
{
	mlx_delete_texture(game->txt->sp_d);
	mlx_delete_texture(game->txt->sprite_left);
	mlx_delete_texture(game->txt->sprite_right);
	mlx_delete_texture(game->txt->sprite_up);
	mlx_delete_texture(game->txt->coin);
	mlx_delete_texture(game->txt->exit);
	mlx_delete_texture(game->txt->path);
	mlx_delete_texture(game->txt->wall);
}

void	ft_cleanup(t_game *game)
{
	if (game->map)
	{
		ft_free(game->map);
		game->map = NULL;
	}
	if (game->txt)
	{
		ft_delete_textures(game);
		free(game->txt);
		game->txt = NULL;
	}
	if (game->image)
	{
		ft_delete_images(game);
		free(game->image);
		game->image = NULL;
	}
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}
