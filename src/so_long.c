/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:02:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/21 20:20:42 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	loop(t_game *game)
{
	draw_background(game);
	move_enemy(game);
	draw_wall(game);
	draw_collectible(game);
	draw_exit(game);
	draw_enemy(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0, 0);
	
	return (EXIT_SUCCESS);
}

int	so_long(char *map)
{
	t_game	game;

	build(map, &game);
	register_hook(&game);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (so_long(av[1]));
	else
		error_msg("Error: Invalid Number of Arguments");
}
