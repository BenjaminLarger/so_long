/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_input_and_read_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:46:20 by blarger           #+#    #+#             */
/*   Updated: 2024/02/07 13:15:17 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static int	check_filename(char *filename, char *ref)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(filename) <= ft_strlen(ref))
		return (0);
	while (filename[i] != '\0')
		i++;
	while (ref[j] != '\0')
		j++;
	while (j > 0)
	{
		if (ref[--j] != filename[--i])
			return (0);
	}
	return (1);
}

char	**check_input(int argc, char *filename, t_map *begin_map)
{
	int		fd;

	if (argc != 2)
		return (free(begin_map), print_error(ARGS_ERROR), NULL);
	if (!check_filename(filename, ".ber"))
		return (free(begin_map), print_error(EXT_ERROR), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(begin_map), print_error(OPEN_FAILED), NULL);
	return (read_map(fd, begin_map));
}

char	**read_map(int fd, t_map *begin_map)
{
	char	*line;
	char	*prev_lines;
	int		raw;
	char	**map;

	line = NULL;
	prev_lines = NULL;
	raw = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		raw++;
		prev_lines = ft_strjoin_free(prev_lines, line);
		free(line);
	}
	if (raw < 3)
		return (free(prev_lines), free(begin_map),
			print_error(RAW_UNSUF), NULL);
	begin_map->raw = raw;
	map = ft_split(prev_lines, '\n');
	return (free(prev_lines), map);
}
