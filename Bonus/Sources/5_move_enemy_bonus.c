/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_move_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:04:30 by blarger           #+#    #+#             */
/*   Updated: 2024/02/10 10:54:09 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	move_enemy_y_2(t_map *game, int n)
{
	if (game->image->play->instances->y > game->image->enm3->instances->y)
		move_e_down(game, n);
	else if (game->image->play->instances->y
		< game->image->enm3->instances->y)
		move_e_up(game, n);
}

void	move_enemy_y(t_map *game, int n)
{
	if (n == 1)
	{
		if (game->image->play->instances->y > game->image->enm1->instances->y)
			move_e_down(game, n);
		else if (game->image->play->instances->y
			< game->image->enm1->instances->y)
			move_e_up(game, n);
	}
	else if (n == 2)
	{
		if (game->image->play->instances->y > game->image->enm2->instances->y)
			move_e_down(game, n);
		else if (game->image->play->instances->y
			< game->image->enm2->instances->y)
			move_e_up(game, n);
	}
	else if (n == 3)
		move_enemy_y_2(game, n);
}

void	move_enemy_x_2(t_map *game)
{
	if (game->enmy_count > 2)
	{
		if (game->image->play->instances->x > game->image->enm3->instances->x)
			move_e_right(game, 3);
		else if (game->image->play->instances->x
			< game->image->enm3->instances->x)
			move_e_left(game, 3);
		else
			move_enemy_y(game, 3);
	}
}

void	move_enemy_x(t_map *game)
{
	if (game->image->play->instances->x > game->image->enm1->instances->x)
		move_e_right(game, 1);
	else if (game->image->play->instances->x < game->image->enm1->instances->x)
		move_e_left(game, 1);
	else
		move_enemy_y(game, 1);
	if (game->enmy_count > 1)
	{
		if (game->image->play->instances->x > game->image->enm2->instances->x)
			move_e_right(game, 2);
		else if (game->image->play->instances->x
			< game->image->enm2->instances->x)
			move_e_left(game, 2);
		else
			move_enemy_y(game, 2);
	}
	move_enemy_x_2(game);
}
