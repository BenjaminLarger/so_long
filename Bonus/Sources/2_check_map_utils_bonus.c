/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_map_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:55:12 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 16:26:49 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	check_for_unknown_char(t_map *get)
{
	int	i;
	int	j;

	i = 0;
	while (i < get->raw)
	{
		j = 0;
		if (!get->map[i])
			return (free_map(get), print_error(HOLE));
		while (j < get->col)
		{
			if (!get->map[i][j])
				return (free_map(get), print_error(INVALID_CHAR));
			if (get->map[i][j] != '1' && get->map[i][j] != '0'
				&& get->map[i][j] != 'P' && get->map[i][j] != 'C'
				&& get->map[i][j] != 'E')
			{
				return (free_map(get), print_error(INVALID_CHAR));
			}
			j++;
		}
		i++;
	}
}

void	valid_vertical_wall(t_map *get)
{
	int	i;

	i = 0;
	while (i < get->raw)
	{
		if (get->map[i][0] != '1')
			return (free(get->map), free(get), print_error(INVALID_WALL));
		i++;
	}
	i = 0;
	while (i < get->raw)
	{
		if (get->map[i][get->col - 1] != '1')
			return (free(get->map), free(get), print_error(INVALID_WALL));
		i++;
	}
}

void	valid_horizontal_wall(t_map *get)
{
	int	i;

	i = 0;
	while (i < get->raw)
	{
		if (get->map[0][i] != '1')
			return (free(get->map), print_error(INVALID_WALL));
		i++;
	}
	i = 0;
	while (i < get->col)
	{
		if (get->map[get->raw - 1][i] != '1')
			return (free_map(get), free(get), print_error(INVALID_WALL));
		i++;
	}
}

void	at_least_one_item(t_map *get)
{
	int	i;
	int	j;
	int	count_item;

	i = 0;
	count_item = 0;
	while (i < get->raw)
	{
		j = 0;
		while (j < get->col)
		{
			if (get->map[i][j] == 'C')
				count_item++;
			j++;
		}
		i++;
	}
	if (count_item < 1)
		return (free_map(get), free(get), print_error(NO_ITEM));
	get->nb_collectible = count_item;
}
