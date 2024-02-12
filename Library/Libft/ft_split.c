/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:54:23 by blarger           #+#    #+#             */
/*   Updated: 2024/02/07 17:14:39 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	in_word = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	**split_init(char const *s, char c, int *start)
{
	char	**arr;

	*start = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 2));
	return (arr);
}

char	**split_main(char const *s, char c, char **arr, int *start)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (*start < ft_strlen(s))
	{
		if (s[*start] != c)
		{
			end = *start;
			while (s[end] != '\0' && s[end] != c)
				end++;
			arr[i] = ft_substr(s, *start, end - *start);
			if (!arr[i])
				return (free(arr), print_error(MALLOC_FAILED), NULL);
			i++;
			*start = end;
		}
		if (s[*start] == c)
			(*start)++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	char	**arr;

	arr = split_init(s, c, &start);
	if (!arr)
		return (print_error(MALLOC_FAILED), NULL);
	return (split_main(s, c, arr, &start));
}
