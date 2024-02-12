/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_collectible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:07:36 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 11:11:47 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	check_end_of_game(t_map *game, int x, int y)
{
	if (game->collected_count == game->nb_collectible
		&& game->map[y][x] == 'E')
	{
		free_images(game);
		mlx_close_window(game->mlx);
	}
}

void	count_collectable(t_map *game, int x_player, int y_player)
{
	int	i;

	i = 0;
	while (i < game->nb_collectible)
	{
		if (game->image->coll->instances[i].x == x_player * SIZE
			&& game->image->coll->instances[i].y == y_player * SIZE
			&& game->image->coll->instances[i].enabled != false)
		{
			game->image->coll->instances[i].enabled = false;
			game->collected_count++;
			return ;
		}
		i++;
	}
}

void	get_collectible(t_map *game)
{
	int	x_player;
	int	y_player;

	x_player = game->image->play->instances->x / SIZE;
	y_player = game->image->play->instances->y / SIZE;
	if (game->map[y_player][x_player] == 'C')
	{
		game->map[y_player][x_player] = '0';
		count_collectable(game, x_player, y_player);
	}
	check_end_of_game(game, x_player, y_player);
}
