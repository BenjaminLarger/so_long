/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:28 by blarger           #+#    #+#             */
/*   Updated: 2024/02/08 17:13:31 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//Error message
# define ARGS_ERROR		"Provide only a map as argumen.t"
# define EXT_ERROR		"Provide a valid map extension (.ber)."
# define OPEN_FAILED	"The file could not be opened."
# define RAW_UNSUF		"The map has too few raws."
# define INVALID_COL	"The number of columns is not the same om each line."
# define NOT_A_RECT		"The map is not a rectangle."
# define INVALID_WALL	"The map must be surrounded by wall."
# define NO_START		"The map must have only one start."
# define NO_EXIT		"The map must have only one exit."
# define NO_ITEM		"The map must have at least one item."
# define MALLOC_FAIL	"Malloc allocation failed."
# define INVALID_WAY	"The map provided has no escape way."
# define INVALID_CHAR	"The map must only contain valid chararcters."
# define HOLE			"The map must not have hole."
# define MLX_INIT		"MLX fail to initialize."
# define IMAGE_FAIL		"Image loading failed."

#endif