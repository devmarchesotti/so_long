/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:14:12 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:14:13 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init(t_game *game)
{
	game->move_count = 0;
	game = set_t_game(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", true);
	if (!game->mlx)
		return (0);
	ft_prep_text(game);
	ft_prep_image(game);
	draw_map(game);
	mlx_image_to_window(game->mlx, game->image->ship, game->player_y * T_S,
		game->player_x * T_S);
	mlx_key_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	ft_cleanup(game);
	return (1);
}

int32_t	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nno arguments or more than 2");
		return (0);
	}
	game.map = ft_load_map(argv[1]);
	if (!game.map)
		return (0);
	if (game_init(&game) == 0)
		printf("Error\nerror initializing game");
	return (0);
}
