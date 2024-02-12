/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_valid_way_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:48:28 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 16:26:52 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	valid_way(t_map *get)
{
	int		i;
	int		j;

	get->visited = (int **)malloc(sizeof(int *) * get->raw);
	if (!get->visited)
		return (free_map(get), free(get), print_error(MALLOC_FAIL));
	i = 0;
	while (i < get->raw)
	{
		get->visited[i] = (int *)malloc(sizeof(int) * get->col);
		if (!get->visited[i])
			return (free(get->visited), free_map(get),
				free(get), print_error(MALLOC_FAIL));
		j = 0;
		while (j < get->col)
		{
			get->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!check_way(get, get->start_raw, get->start_col))
		return (free_array(get), free_map(get),
			free(get), print_error(INVALID_WAY));
	free_array(get);
}

int	check_way(t_map *get, int y, int x)
{
	if (x < 0 || y < 0 || y >= get->raw || x >= get->col
		|| get->visited[y][x] != 0)
		return (0);
	get->visited[y][x] = 1;
	if (get->map[y][x] == 'E')
	{
		return (1);
	}
	if ((get->map[y][x] == 'P' || get->map[y][x] == 'C'
	|| get->map[y][x] == '0'))
	{
		if (check_way(get, y - 1, x) || check_way(get, y + 1, x)
			|| check_way(get, y, x - 1) || check_way(get, y, x + 1))
		{
			return (1);
		}
	}
	return (0);
}
