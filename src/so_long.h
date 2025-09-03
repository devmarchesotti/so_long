/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:14:20 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:14:23 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_libft/src/libft.h"

# define WIDTH 1024
# define HEIGHT 512
# define T_S 32

typedef struct s_game
{
	struct s_texture	*txt;
	struct s_image		*image;
	mlx_t				*mlx;
	int					player_x;
	int					player_y;
	int					total_coin;
	char				**map;
	int					map_width;
	int					map_height;
	int					move_count;
}	t_game;

typedef struct s_texture
{
	mlx_texture_t	*sprite_up;
	mlx_texture_t	*sp_d;
	mlx_texture_t	*sprite_left;
	mlx_texture_t	*sprite_right;
	mlx_texture_t	*path;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*ship;
	mlx_image_t	*tile_path;
	mlx_image_t	*tile_wall;
	mlx_image_t	*tile_coin;
	mlx_image_t	*tile_exit;
}	t_image;

typedef struct s_point
{
	int	row;
	int	col;
	int	max_rows;
	int	max_cols;
	int	n_collect;
}	t_point;

int		ft_checker(char **map, int rows, int cols);
int		ft_read_map(int fd, char **map, int *rows, int *cols);
char	**ft_create_map(char *filename, char **map, int *rows, int *cols);
int		ft_check_move(int new_x, int new_y, t_game *game);
int		game_init(t_game *game);
void	update_player_image(t_game *game, int direction);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	ft_prep_text(t_game *game);
void	ft_prep_image(t_game *game);
int		handle_movement(t_game *game, mlx_key_data_t keydata);
int		ft_move_right(t_game *game, int new_x, int new_y, int direction);
int		ft_move_left(t_game *game, int new_x, int new_y, int direction);
int		ft_move_up(t_game *game, int new_x, int new_y, int direction);
int		ft_move_down(t_game *game, int new_x, int new_y, int direction);
void	ft_delete_images(t_game *game);
void	ft_delete_textures(t_game *game);
void	ft_cleanup(t_game *game);
void	draw_map(t_game *game);
t_game	*set_t_game(t_game *game);
bool	is_valid_move(int new_x, int new_y, t_game *game);
int		flood_map(char **map, int rows, int cols);
char	**ft_parse_map(char *filename, int *rows, int *cols);
char	**ft_load_map(char *filename);
int		count_itens(char **map, int rows, int cols);
int		check_empty(char **map, int rows);
int		check_letters(char **map, int rows, int cols);
void	find_p(t_point *p, int rows, int cols, char **map);

#endif
