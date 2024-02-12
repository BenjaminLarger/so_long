/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_collectible_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:07:36 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 19:05:27 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	check_end_of_game(t_map *game, int x, int y)
{
	if (game->collected_count == game->nb_collectible
		&& game->map[y][x] == 'E')
	{
		free_images(game);
		mlx_close_window(game->mlx);
	}
}

int	check_collusion(t_map *game)
{
	int	x_player;
	int	y_player;

	x_player = game->image->play->instances->x / SIZE;
	y_player = game->image->play->instances->y / SIZE;
	if (x_player == game->image->enm1->instances->x / SIZE
		&& y_player == game->image->enm1->instances->y / SIZE)
	{
		return (free_images(game), mlx_close_window(game->mlx), 0);
	}
	else if (game->enmy_count > 1
		&& x_player == game->image->enm2->instances->x / SIZE
		&& y_player == game->image->enm2->instances->y / SIZE)
	{
		return (free_images(game), mlx_close_window(game->mlx), 0);
	}
	else if (game->enmy_count > 2
		&& x_player == game->image->enm3->instances->x / SIZE
		&& y_player == game->image->enm3->instances->y / SIZE)
	{
		return (free_images(game), mlx_close_window(game->mlx), 0);
	}
	return (1);
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
	check_collusion(game);
	if (game->map[y_player][x_player] == 'C')
	{
		game->map[y_player][x_player] = '0';
		count_collectable(game, x_player, y_player);
	}
	check_end_of_game(game, x_player, y_player);
}
