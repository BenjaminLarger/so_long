/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:40:09 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 17:10:19 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Local library
# include "../Library/Libft/libft.h"
# include "../Library/MLX42/include/MLX42/MLX42.h"
# include "list.h"
# include "error.h"
# define SIZE 32

//0_main.c
void	print_error(char *str);

//1_check_input_and_read_map.c
char	**check_input(int argc, char *filename, t_map *begin_map);
char	**read_map(int fd, t_map *begin_map);

//1_check_input_and_read_map._utils.c
char	*jointure_free(char *str, char *s2, int i, int length);
char	*ft_strjoin_free(char *s1, char *s2);
void	only_valid_char(t_map *get);

//2_check_map.c
void	check_map(t_map *begin_map);
void	is_rectangle(t_map *begin_map);
void	only_one_start(t_map *begin_map);
void	only_one_exit(t_map *begin_map);
void	save_position(int i, int j, t_map *begin_map, char c);

//2_check_map_utils.c
void	at_least_one_item(t_map *begin_map);
void	valid_vertical_wall(t_map *begin_map);
void	valid_horizontal_wall(t_map *begin_map);
void	check_for_unknown_char(t_map *get);

//2_valid_way.c
void	valid_way(t_map *get);
int		check_way(t_map *get, int x, int y);

//3_mlx_features.c
void	start_mlx(t_map *map);
void	start_game(t_map *game);

//4_get_visual.c
int		create_textures(t_map *game);
int		create_images(t_map *g);

//5_moves.c
void	move_up(t_map *game);
void	move_left(t_map *game);
void	move_down(t_map *game);
void	move_right(t_map *game);
void	mlx_key_data(mlx_key_data_t keydata, void *param);

//6_collectible.c
void	get_collectible(t_map *game);

//7_free.c
void	free_map(t_map *get);
void	free_array(t_map *get);
void	free_textures(t_map *g);
void	free_images(t_map *g);

#endif