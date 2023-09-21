/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:48:59 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/21 23:07:48 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	int	y;
	int	x;

	y = game->player->coord->y / BLOCK_PIXEL;
	x = game->player->coord->x / BLOCK_PIXEL;
	if (game->total_collectibles == 0 && game->map->matrix[y][x] == 'E')
	{
		msg("!!! You win !!!");
		end_game(game);
	}
}

t_buffer	*get_exit_sprite(t_game *game)
{
	if (game->total_collectibles == 0 && game->exit_animation_pos == 10)
	{
		if (game->exit_animation != E_END)
			game->exit_animation += 1;
		game->exit_animation_pos = 0;
	}
	else if (game->total_collectibles == 0)
		game->exit_animation_pos++;
	return (&game->sprites->exit[game->exit_animation]);
}

void	draw_exit(t_game *game)
{
	draw(game->exit->coord->x / BLOCK_PIXEL, game->exit->coord->y / BLOCK_PIXEL,
		get_exit_sprite(game), game);
}
