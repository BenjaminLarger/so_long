/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:42:38 by blarger           #+#    #+#             */
/*   Updated: 2024/01/25 10:40:10 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include "error_libft.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strcat_mal(char *dest, char *src);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif