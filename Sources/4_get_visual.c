/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_get_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:05:26 by blarger           #+#    #+#             */
/*   Updated: 2024/02/07 16:59:09 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	draw_dynamic(t_map *g)
{
	int	i;
	int	j;

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

int	create_images(t_map *g) //LEAKS AQUI
{
	g->image = malloc(sizeof(t_images));
	if (!g->image)
		return (free_textures(g), free(g->texture), 0);
	g->image->coll = mlx_texture_to_image(g->mlx, g->texture->collect);
	g->image->floor = mlx_texture_to_image(g->mlx, g->texture->floor);
	g->image->exit = mlx_texture_to_image(g->mlx, g->texture->exit);
	g->image->play = mlx_texture_to_image(g->mlx, g->texture->player);
	g->image->wall = mlx_texture_to_image(g->mlx, g->texture->wall);
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
	create_images(game);
	return (1);
}
