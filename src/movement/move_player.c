/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:54:01 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:38:48 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (player->coord->x < (game->map->width * BLOCK_PIXEL)
		&& !is_right_wall(game, player->coord))
	{
		game->player->last_coord->x = game->player->coord->x;
		game->player->coord->x += BLOCK_PIXEL;
		game->player->steps++;
	}
}

void	move_left_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (player->coord->x > 1 && !is_left_wall(game, player->coord))
	{
		game->player->last_coord->x = game->player->coord->x;
		game->player->coord->x -= BLOCK_PIXEL;
		game->player->steps++;
	}
}

void	move_up_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (player->coord->y > 1 && !is_up_wall(game, player->coord))
	{
		game->player->last_coord->y = game->player->coord->y;
		game->player->coord->y -= BLOCK_PIXEL;
		game->player->steps++;
	}
}

void	move_down_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (player->coord->y < (game->map->height * BLOCK_PIXEL)
		&& !is_down_wall(game, player->coord))
	{
		game->player->last_coord->y = game->player->coord->y;
		game->player->coord->y += BLOCK_PIXEL;
		game->player->steps++;
	}
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == LETTER_KEY_LEFT || keycode == ARROW_KEY_LEFT)
		move_left_player(game);
	else if (keycode == LETTER_KEY_RIGHT || keycode == ARROW_KEY_RIGHT)
		move_right_player(game);
	else if (keycode == LETTER_KEY_UP || keycode == ARROW_KEY_UP)
		move_up_player(game);
	else if (keycode == LETTER_KEY_DOWN || keycode == ARROW_KEY_DOWN)
		move_down_player(game);
	get_item(game);
	exit_game(game);
}
