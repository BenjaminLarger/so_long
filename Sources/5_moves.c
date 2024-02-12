/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:59:33 by blarger           #+#    #+#             */
/*   Updated: 2024/02/07 09:14:01 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	move_up(t_map *game)
{
	if (game->map[game->image->play->instances->y / SIZE - 1]
		[game->image->play->instances->x / SIZE] != '1')
	{
		game->image->play->instances->y -= SIZE;
		game->moves_cont++;
		ft_printf("Moves count = %d\n", game->moves_cont);
	}
}

void	move_left(t_map *game)
{
	if (game->map[game->image->play->instances->y / SIZE]
		[game->image->play->instances->x / SIZE - 1] != '1')
	{
		game->image->play->instances->x -= SIZE;
		game->moves_cont++;
		ft_printf("Moves count = %d\n", game->moves_cont);
	}
}

void	move_down(t_map *game)
{
	if (game->map[game->image->play->instances->y / SIZE + 1]
		[game->image->play->instances->x / SIZE] != '1')
	{
		game->image->play->instances->y += SIZE;
		game->moves_cont++;
		ft_printf("Moves count = %d\n", game->moves_cont);
	}
}

void	move_right(t_map *game)
{
	if (game->map[game->image->play->instances->y / SIZE]
		[game->image->play->instances->x / SIZE + 1] != '1')
	{
		game->image->play->instances->x += SIZE;
		game->moves_cont++;
		ft_printf("Moves count = %d\n", game->moves_cont);
	}
}
