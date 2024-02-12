/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mlx_features_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:05:47 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 18:51:34 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

/* First, we need to initialize the mlx with mlx_init(),
that returns a pointer (void *) that we need to save because a 
lot of the library functions need it in order to work.
After instantiating the MLX library, you will be able to create a window. */

void	start_mlx(t_map *game)
{
	game->mlx = mlx_init(game->col * SIZE, game->raw * SIZE, "so_long", true);
	if (!game->mlx)
		return (free_map(game), free(game), print_error(MLX_INIT));
}

void	mlx_key_data(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	else if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	else if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	else if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		free(game->image);
		mlx_close_window(game->mlx);
	}
}

void	start_game(t_map *map)
{
	map->moves_cont = 0;
	map->collected_count = 0;
	if (!create_textures(map))
		return (free_map(map), free(map), print_error(MALLOC_FAIL));
	mlx_put_string(map->mlx, "Moves :", map->raw * 3, map->col * 30);
}
