/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:55:14 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 17:10:52 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	check_map(t_map *get)
{
	check_for_unknown_char(get);
	is_rectangle(get);
	only_valid_char(get);
	only_one_start(get);
	only_one_exit(get);
	at_least_one_item(get);
	valid_vertical_wall(get);
	valid_horizontal_wall(get);
	valid_way(get);
}

void	is_rectangle(t_map *get)
{
	int	i;
	int	j;
	int	first_col;

	i = 0;
	first_col = 0;
	while (get->map[i][first_col] != '\n' && get->map[i][first_col] != '\0')
		first_col++;
	while (get->map[i] != NULL)
	{
		j = 0;
		while (get->map[i][j] != '\n' && get->map[i][j] != '\0')
			j++;
		if (j != first_col)
			return (free_map(get), free(get), print_error(NOT_A_RECT));
		i++;
	}
	get->col = first_col;
}

void	only_one_start(t_map *get)
{
	int	i;
	int	j;
	int	count_start;

	i = 0;
	count_start = 0;
	while (i < get->raw)
	{
		j = 0;
		while (j < get->col)
		{
			if (get->map[i][j] == 'P')
			{
				count_start++;
				save_position(i, j, get, get->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (count_start != 1)
		return (free_map(get), free(get), print_error(NO_START));
}

void	only_one_exit(t_map *get)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (i < get->raw)
	{
		j = 0;
		while (j < get->col)
		{
			if (get->map[i][j] == 'E')
			{
				count_exit++;
				save_position(i, j, get, get->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (count_exit != 1)
		return (free_map(get), free(get), print_error(NO_EXIT));
}

void	save_position(int i, int j, t_map *begin_map, char c)
{
	if (c == 'P')
	{
		begin_map->start_raw = i;
		begin_map->start_col = j;
	}
	else if (c == 'E')
	{
		begin_map->exit_raw = i;
		begin_map->exit_col = j;
	}
}
