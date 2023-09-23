/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:52:25 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/23 23:56:24 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_mlx_itens(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * BLOCK_PIXEL,
			game->map->height * BLOCK_PIXEL, WINDOW_TITLE);
	game->image_buffer.img = mlx_new_image(game->mlx, game->map->width
			* BLOCK_PIXEL, game->map->height * BLOCK_PIXEL);
	game->image_buffer.addr = mlx_get_data_addr(game->image_buffer.img,
			&game->image_buffer.bits_per_pixel, &game->image_buffer.line_length,
			&game->image_buffer.endian);
	game->image_buffer.width = game->map->width * BLOCK_PIXEL;
	game->image_buffer.height = game->map->height * BLOCK_PIXEL;
}

void	build_game(t_game *game)
{
	game->exit_animation_pos = E_START;
	game->exit_animation = E_START;
	game->enemies = NULL;
	game->collectibles = NULL;
	game->total_collectibles = 0;
	game->nbr_player = 0;
	game->nbr_exit = 0;
	game->mlx = NULL;
}

void	build_characters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->matrix[y][x] == 'P')
				build_player(game, x, y);
			else if (game->map->matrix[y][x] == 'M')
				build_enemy(game, x, y);
			else if (game->map->matrix[y][x] == 'C')
				build_collectible(game, x, y);
			else if (game->map->matrix[y][x] == 'E')
				build_exit(game, x, y);
			x++;
		}
		y++;
	}
}

void	build(char *map, t_game *game)
{
	build_map(map, game);
	build_game(game);
	build_characters(game);
	valid_map(game);
	build_mlx_itens(game);
	build_sprites(game);
}
