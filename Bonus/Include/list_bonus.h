/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:44 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 10:14:45 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_BONUS_H
# define LIST_BONUS_H
# include "so_long_bonus.h"

// ----------- TEXTURES
typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*enm1;
	mlx_texture_t	*enm2;
	mlx_texture_t	*enm3;
	mlx_texture_t	*exit;
	mlx_texture_t	*collect;
}				t_textures;

// ----------- IMAGES
typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*play;
	mlx_image_t	*enm1;
	mlx_image_t	*enm2;
	mlx_image_t	*enm3;
	mlx_image_t	*exit;
	mlx_image_t	*coll;
}			t_images;

// ---------- MAP
typedef struct s_map
{
	int					col;
	int					raw;
	int					start_raw;
	int					start_col;
	int					**visited;
	struct s_textures	*texture;
	struct s_images		*image;
	mlx_t				*mlx;
	int					map_height;
	int					map_width;
	int					moves_cont;
	int					nb_collectible;
	int					collected_count;
	int					enmy_count;
	char				**map;
	int					exit_raw; //not used for now
	int					exit_col; //not used for now
}				t_map;

#endif