/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:02:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 23:04:34 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	draw_background(game);
	if (game->end_game == 0)
	{
		move_enemy(game);
		draw_wall(game);
		draw_collectible(game);
		draw_exit(game);
		draw_enemy(game);
		draw_player(game);
	}
	else
	{
		select_option(game);
	}
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
