/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:52:25 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:25:03 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * BLOCK_PIXEL,
			game->map->height * BLOCK_PIXEL, WINDOW_TITLE);
	game->exit_animation_pos = E_START;
	game->exit_animation = E_START;
	game->enemies = NULL;
	game->collectibles = NULL;
	game->total_collectibles = 0;
	game->arrow_position = LETTER_KEY_UP;
	game->end_game = 0;
	game->nbr_player = 0;
	game->nbr_exit = 0;
}

void	build(char *map, t_game *game)
{
	build_map(map, game);
	build_game(game);
	build_collectibles(game);
	build_player(game);
	build_enemies(game);
	build_sprites(game);
	build_exit(game);
	valid_map(game);
}
