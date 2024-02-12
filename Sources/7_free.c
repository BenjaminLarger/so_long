/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:48:41 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 11:17:05 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	free_map(t_map *get)
{
	int	i;

	i = 0;
	while (i < get->raw)
	{
		free(get->map[i]);
		i++;
	}
	free(get->map);
}

void	free_array(t_map *get)
{
	int	i;

	i = 0;
	while (i < get->raw)
	{
		free(get->visited[i]);
		i++;
	}
	free(get->visited);
}

void	free_textures(t_map *g)
{
	if (g->texture)
	{
		if (g->texture->collect)
			mlx_delete_texture(g->texture->collect);
		if (g->texture->floor)
			mlx_delete_texture(g->texture->floor);
		if (g->texture->exit)
			mlx_delete_texture(g->texture->exit);
		if (g->texture->player)
			mlx_delete_texture(g->texture->player);
		if (g->texture->wall)
			mlx_delete_texture(g->texture->wall);
		free(g->texture);
	}
}

void	free_images(t_map *g)
{
	if (g->image)
	{
		if (g->image->coll)
			mlx_delete_image(g->mlx, g->image->coll);
		if (g->image->floor)
			mlx_delete_image(g->mlx, g->image->floor);
		if (g->image->exit)
			mlx_delete_image(g->mlx, g->image->exit);
		if (g->image->play)
			mlx_delete_image(g->mlx, g->image->play);
		if (g->image->wall)
			mlx_delete_image(g->mlx, g->image->wall);
		free(g->image);
	}
}
