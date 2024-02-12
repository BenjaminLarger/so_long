/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_moves_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:58 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 19:03:01 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	move_count_on_window(t_map *game)
{
	char	*str;

	mlx_image_to_window(game->mlx, game->image->wall,
		game->raw * 10, SIZE * game->col);
	str = ft_itoa(game->moves_cont);
	mlx_put_string(game->mlx, str,
		game->raw * 10, game->col * SIZE);
	free(str);
}

void	move_up(t_map *game)
{
	if (game->map[game->image->play->instances->y / SIZE - 1]
		[game->image->play->instances->x / SIZE] != '1')
	{
		game->image->play->instances->y -= SIZE;
		game->moves_cont++;
		ft_printf("Moves count = %d\n", game->moves_cont);
		move_count_on_window(game);
		if (!check_collusion(game))
			return ;
		move_enemy_x(game);
		get_collectible(game);
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
		move_count_on_window(game);
		if (!check_collusion(game))
			return ;
		move_enemy_x(game);
		get_collectible(game);
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
		move_count_on_window(game);
		if (!check_collusion(game))
			return ;
		move_enemy_x(game);
		get_collectible(game);
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
		move_count_on_window(game);
		if (!check_collusion(game))
			return ;
		move_enemy_x(game);
		get_collectible(game);
	}
}
