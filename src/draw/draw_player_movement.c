/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:22:47 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:36:32 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_walk_sprite_left(t_game *game)
{
	if (game->player->animation == PSL_END)
		game->player->animation = PSL_START_RUN;
	else if (game->player->animation >= PSL_START_RUN
		&& game->player->animation <= PSL_END)
		game->player->animation += 1;
	else
		game->player->animation = PSL_START_RUN;
}

void	player_walk_sprite_right(t_game *game)
{
	if (game->player->animation == PSR_END)
		game->player->animation = PSR_START_RUN;
	else if (game->player->animation >= PSR_START_RUN
		&& game->player->animation <= PSR_END)
		game->player->animation += 1;
	else
		game->player->animation = PSR_START_RUN;
}

void	player_walk_sprite_down(t_game *game)
{
	if (game->player->animation == PSD_END)
		game->player->animation = PSD_START_RUN;
	else if (game->player->animation >= PSD_START_RUN
		&& game->player->animation <= PSD_END)
		game->player->animation += 1;
	else
		game->player->animation = PSD_START_RUN;
}

void	player_walk_sprite_up(t_game *game)
{
	if (game->player->animation == PSD_END)
		game->player->animation = PSU_START_RUN;
	else if (game->player->animation >= PSU_START_RUN
		&& game->player->animation <= PSU_END)
		game->player->animation += 1;
	else
		game->player->animation = PSU_START_RUN;
}

int	player_walk_sprite(t_game *game)
{
	if (game->player->coord->x > game->player->last_coord->x)
		player_walk_sprite_left(game);
	else if (game->player->coord->x < game->player->last_coord->x)
		player_walk_sprite_right(game);
	else if (game->player->coord->y > game->player->last_coord->y)
		player_walk_sprite_down(game);
	else if (game->player->coord->y < game->player->last_coord->y)
		player_walk_sprite_up(game);
	game->player->last_coord->y = game->player->coord->y;
	game->player->last_coord->x = game->player->coord->x;
	return (game->player->animation);
}
