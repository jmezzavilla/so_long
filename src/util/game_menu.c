/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:55:56 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/19 19:00:18 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	destroy_game(game);
	mlx_loop_end(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	put_arrows(t_game *game, int direction)
{
	int	x;
	int	y;

	x = (BLOCK_PIXEL * game->map->width) / 2;
	y = ((BLOCK_PIXEL * game->map->height) / 2);
	mlx_string_put(game->mlx, game->window, x, y + BLOCK_PIXEL, 16777215,
		"Try Again");
	mlx_string_put(game->mlx, game->window, x, y + BLOCK_PIXEL * 2, 16777215,
		"EXIT");
	if (direction == LETTER_KEY_UP)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->tiles[2], x - BLOCK_PIXEL, y);
		mlx_string_put(game->mlx, game->window, x - BLOCK_PIXEL, y
			+ BLOCK_PIXEL, 16777215, ">");
		game->arrow_position = LETTER_KEY_UP;
	}
	else if (direction == LETTER_KEY_DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->tiles[2], x - BLOCK_PIXEL, y + BLOCK_PIXEL);
		mlx_string_put(game->mlx, game->window, x - BLOCK_PIXEL, y + BLOCK_PIXEL
			* 2, 16777215, ">");
		game->arrow_position = LETTER_KEY_DOWN;
	}
}

void	select_option(t_game *game)
{
	int	x;
	int	y;

	x = (BLOCK_PIXEL * game->map->width) / 2;
	y = (BLOCK_PIXEL * game->map->height) / 2;
	draw_map_game_over(game);
	if (game->end_game == -1)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->game_over[1], x, y - (2 * BLOCK_PIXEL));
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->game_over[0], x - (3 * BLOCK_PIXEL), y - (2
				* BLOCK_PIXEL));
	}
	else if (game->end_game == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->game_over[2], x - (BLOCK_PIXEL / 2), y - (2
				* BLOCK_PIXEL));
	put_arrows(game, game->arrow_position);
}
