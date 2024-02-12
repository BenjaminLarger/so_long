/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_move_enemy_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:19:05 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 19:02:29 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	move_e_up(t_map *game, int n)
{
	if (n == 1)
	{
		if (game->map[game->image->enm1->instances->y / SIZE - 1]
			[game->image->enm1->instances->x / SIZE] != '1'
			&& valid_enemy1_move(game, 0, -32))
			game->image->enm1->instances->y -= SIZE;
	}
	else if (n == 2)
	{
		if (game->map[game->image->enm2->instances->y / SIZE - 1]
			[game->image->enm2->instances->x / SIZE] != '1'
			&& valid_enemy2_move(game, 0, -32))
			game->image->enm2->instances->y -= SIZE;
	}
	else if (n == 3)
	{
		if (game->map[game->image->enm3->instances->y / SIZE - 1]
			[game->image->enm3->instances->x / SIZE] != '1'
			&& valid_enemy3_move(game, 0, -32))
			game->image->enm3->instances->y -= SIZE;
	}
}

void	move_e_left(t_map *game, int n)
{
	if (n == 1 && game->map[game->image->enm1->instances->y / SIZE]
		[game->image->enm1->instances->x / SIZE - 1] != '1'
		&& valid_enemy1_move(game, -32, 0))
		game->image->enm1->instances->x -= SIZE;
	else
		move_enemy_y(game, n);
	if (n == 2 && game->map[game->image->enm2->instances->y / SIZE]
		[game->image->enm2->instances->x / SIZE - 1] != '1'
		&& valid_enemy2_move(game, -32, 0))
		game->image->enm2->instances->x -= SIZE;
	else
		move_enemy_y(game, n);
	if (n == 3 && game->map[game->image->enm3->instances->y / SIZE]
		[game->image->enm3->instances->x / SIZE - 1] != '1'
		&& valid_enemy3_move(game, -32, 0))
		game->image->enm3->instances->x -= SIZE;
	else
		move_enemy_y(game, n);
}

void	move_e_down(t_map *game, int n)
{
	if (n == 1 && game->map[game->image->enm1->instances->y / SIZE + 1]
		[game->image->enm1->instances->x / SIZE] != '1'
		&& valid_enemy1_move(game, 0, 32))
		game->image->enm1->instances->y += SIZE;
	if (n == 2 && game->map[game->image->enm2->instances->y / SIZE + 1]
		[game->image->enm2->instances->x / SIZE] != '1'
		&& valid_enemy2_move(game, 0, 32))
		game->image->enm2->instances->y += SIZE;
	if (n == 3 && game->map[game->image->enm3->instances->y / SIZE + 1]
		[game->image->enm3->instances->x / SIZE] != '1'
		&& valid_enemy3_move(game, 0, 32))
		game->image->enm3->instances->y += SIZE;
}

void	move_e_right(t_map *game, int n)
{
	if (n == 1 && game->map[game->image->enm1->instances->y / SIZE]
		[game->image->enm1->instances->x / SIZE + 1] != '1'
		&& valid_enemy1_move(game, 32, 0))
		game->image->enm1->instances->x += SIZE;
	else
		move_enemy_y(game, n);
	if (n == 2 && game->map[game->image->enm2->instances->y / SIZE]
		[game->image->enm2->instances->x / SIZE + 1] != '1'
		&& valid_enemy2_move(game, 32, 0))
		game->image->enm2->instances->x += SIZE;
	else
		move_enemy_y(game, n);
	if (n == 3 && game->map[game->image->enm3->instances->y / SIZE]
		[game->image->enm3->instances->x / SIZE + 1] != '1'
		&& valid_enemy3_move(game, 32, 0))
		game->image->enm3->instances->x += SIZE;
	else
		move_enemy_y(game, n);
}
