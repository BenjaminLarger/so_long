/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_valid_enemy_move_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:24:32 by blarger           #+#    #+#             */
/*   Updated: 2024/02/10 10:56:35 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

int	valid_enemy1_move(t_map *game, int x_p, int y_p)
{
	int	x_enm1;
	int	y_enm1;

	x_enm1 = game->image->enm1->instances->x + x_p;
	y_enm1 = game->image->enm1->instances->y + y_p;
	if (game->enmy_count > 1)
	{
		if (y_enm1 == game->image->enm2->instances->y
			&& x_enm1 == game->image->enm2->instances->x)
			return (0);
		if (game->enmy_count == 3)
		{
			if (y_enm1 == game->image->enm3->instances->y
				&& x_enm1 == game->image->enm3->instances->x)
				return (0);
		}
	}
	return (1);
}

int	valid_enemy2_move(t_map *game, int x_p, int y_p)
{
	int	x_enm2;
	int	y_enm2;

	x_enm2 = game->image->enm2->instances->x + x_p;
	y_enm2 = game->image->enm2->instances->y + y_p;
	if (y_enm2 == game->image->enm1->instances->y
		&& x_enm2 == game->image->enm1->instances->x)
		return (0);
	if (game->enmy_count == 3)
	{
		if (y_enm2 == game->image->enm3->instances->y
			&& x_enm2 == game->image->enm3->instances->x)
			return (0);
	}
	return (1);
}

int	valid_enemy3_move(t_map *game, int x_p, int y_p)
{
	int	x_enm3;
	int	y_enm3;

	x_enm3 = game->image->enm3->instances->x + x_p;
	y_enm3 = game->image->enm3->instances->y + y_p;
	if (y_enm3 == game->image->enm1->instances->y
		&& x_enm3 == game->image->enm1->instances->x)
		return (0);
	if (y_enm3 == game->image->enm3->instances->y
		&& x_enm3 == game->image->enm3->instances->x)
		return (0);
	return (1);
}
