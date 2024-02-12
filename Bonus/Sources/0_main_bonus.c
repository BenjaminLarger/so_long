/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:23:47 by blarger           #+#    #+#             */
/*   Updated: 2024/02/09 18:50:18 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*get;

	get = malloc(sizeof(t_map));
	if (!get)
		return (print_error(MALLOC_FAIL), -1);
	get->map = check_input(argc, argv[1], get);
	check_map(get);
	start_mlx(get);
	start_game(get);
	mlx_key_hook(get->mlx, &mlx_key_data, get);
	mlx_loop(get->mlx);
	mlx_terminate(get->mlx);
	free_map(get);
	free(get);
}
