/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_get_visual_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:05:26 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 18:57:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	draw_enemy(t_map *g, int drawn_enemy, int i, int j)
{
	while (i < g->raw)
	{
		j = 0;
		while (j < g->col)
		{
			if (g->map[i][j] == 'X' && drawn_enemy == 0)
			{
				drawn_enemy++;
				mlx_image_to_window(g->mlx, g->image->enm1, j * SIZE, i * SIZE);
			}
			else if (g->map[i][j] == 'X' && drawn_enemy == 1)
			{
				drawn_enemy++;
				mlx_image_to_window(g->mlx, g->image->enm2, j * SIZE, i * SIZE);
			}
			else if (g->map[i][j] == 'X' && drawn_enemy == 2)
			{
				drawn_enemy++;
				mlx_image_to_window(g->mlx, g->image->enm3, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
}

void	draw_dynamic(t_map *g)
{
	int	i;
	int	j;
	int	drawn_enemy;

	drawn_enemy = 0;
	i = 0;
	while (i < g->raw)
	{
		j = 0;
		while (j < g->col)
		{
			if (g->map[i][j] == 'P')
				mlx_image_to_window(g->mlx, g->image->play, j * SIZE, i * SIZE);
			else if (g->map[i][j] == 'C')
				mlx_image_to_window(g->mlx, g->image->coll, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	i = 0;
	draw_enemy(g, drawn_enemy, i, j);
}

void	draw_floor(t_map *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->raw)
	{
		j = 0;
		while (j < g->col)
		{
			mlx_image_to_window(g->mlx, g->image->floor, j * SIZE, i * SIZE);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->image->wall, j * SIZE, i * SIZE);
			else if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->image->exit, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	draw_dynamic(g);
}

int	create_images(t_map *g)
{
	g->image = malloc(sizeof(t_images));
	if (!g->image)
		return (free_textures(g), free(g->texture), 0);
	g->image->coll = mlx_texture_to_image(g->mlx, g->texture->collect);
	g->image->floor = mlx_texture_to_image(g->mlx, g->texture->floor);
	g->image->exit = mlx_texture_to_image(g->mlx, g->texture->exit);
	g->image->play = mlx_texture_to_image(g->mlx, g->texture->player);
	g->image->wall = mlx_texture_to_image(g->mlx, g->texture->wall);
	g->image->enm1 = mlx_texture_to_image(g->mlx, g->texture->enm1);
	if (g->enmy_count > 1)
		g->image->enm2 = mlx_texture_to_image(g->mlx, g->texture->enm2);
	if (g->enmy_count > 2)
		g->image->enm3 = mlx_texture_to_image(g->mlx, g->texture->enm3);
	free_textures(g);
	draw_floor(g);
	return (1);
}

int	create_textures(t_map *game)
{
	game->texture = malloc(sizeof(t_textures));
	if (!game->texture)
		return (0);
	game->texture->wall = mlx_load_png("./Textures/32*32/Wall.png");
	game->texture->floor = mlx_load_png("./Textures/32*32/Stars.png");
	game->texture->player = mlx_load_png("./Textures/32*32/Spaceship.png");
	game->texture->exit = mlx_load_png("./Textures/32*32/PlanetYellow.png");
	game->texture->collect = mlx_load_png("./Textures/32*32/Spark.png");
	game->texture->enm1 = mlx_load_png("./Textures/32*32/Enemy.png");
	if (game->enmy_count > 1)
		game->texture->enm2 = mlx_load_png("./Textures/32*32/Enemy.png");
	if (game->enmy_count > 2)
		game->texture->enm3 = mlx_load_png("./Textures/32*32/Enemy.png");
	create_images(game);
	return (1);
}
