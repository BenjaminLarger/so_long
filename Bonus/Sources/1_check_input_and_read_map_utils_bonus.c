/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_input_and_read_map_utils_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:14:54 by blarger           #+#    #+#             */
/*   Updated: 2024/02/10 09:55:43 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

char	*jointure_free(char *str, char *s2, int i, int length)
{
	int		j;

	j = 0;
	while (j < length)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*str;

	l1 = 0;
	l2 = 0;
	if (s1 != NULL)
		l1 = ft_strlen(s1);
	if (s2 != NULL)
		l2 = ft_strlen(s2);
	str = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	jointure_free(str, s2, i, l2);
	free(s1);
	str[l1 + l2] = '\0';
	return (str);
}

void	at_least_one_enemy(t_map *get)
{
	int	i;
	int	j;
	int	count_enemy;

	i = 0;
	count_enemy = 0;
	while (i < get->raw)
	{
		j = 0;
		while (j < get->col)
		{
			if (get->map[i][j] == 'X')
			{
				count_enemy++;
			}
			j++;
		}
		i++;
	}
	if (count_enemy < 1 || count_enemy > 3)
		return (free_map(get), free(get), print_error(NO_ENEMY));
	get->enmy_count = count_enemy;
}

void	only_valid_char(t_map *get)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < get->raw)
	{
		j = 0;
		while (j < get->col)
		{
			c = get->map[i][j];
			if (c != 'X' && c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P')
			{
				return (free_map(get), free(get), print_error(INVALID_CHAR));
			}
			j++;
		}
		i++;
	}
}
