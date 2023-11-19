/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:56:05 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/19 19:11:52 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*build_coord(t_game *game, int x, int y)
{
	t_coord	*coord;

	coord = ft_calloc(sizeof(t_coord), 1);
	if (coord == NULL)
		error_msg("Error: coord", game);
	coord->x = x * BLOCK_PIXEL;
	coord->y = y * BLOCK_PIXEL;
	return (coord);
}

void	build_player(t_game *game, int x, int y)
{
	if (game->nbr_player == 0)
	{
		game->player = ft_calloc(sizeof(t_player), 1);
		game->player->last_coord = ft_calloc(sizeof(t_coord), 1);
		if (game->player == NULL || game->player->last_coord == NULL)
			error_msg("Error: memory player", game);
		game->player->coord = build_coord(game, x, y);
		game->flood_fill->x = x;
		game->flood_fill->y = y;
	}
	game->nbr_player++;
}

void	build_exit(t_game *game, int x, int y)
{
	if (game->nbr_exit == 0)
	{
		game->exit = ft_calloc(sizeof(t_exit), 1);
		if (game->exit == NULL)
			error_msg("Error: Memory game->exit", game);
		game->exit->coord = build_coord(game, x, y);
	}
	game->nbr_exit++;
}

void	build_collectible(t_game *game, int x, int y)
{
	t_collectible	*collectible;

	collectible = ft_calloc(sizeof(t_collectible), 1);
	if (collectible == NULL)
		error_msg("Error: Memory collectible", game);
	collectible->coord = build_coord(game, x, y);
	collectible->is_collected = 0;
	collectible->animation = 0;
	collectible->animation_pos = 0;
	game->total_collectibles++;
	ft_lstadd_back(&game->collectibles, ft_lstnew(collectible));
}

void	build_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = ft_calloc(sizeof(t_enemy), 1);
	if (enemy == NULL)
		error_msg("Error: Memory enemy", game);
	enemy->coord = build_coord(game, x, y);
	enemy->last_coord = ft_calloc(sizeof(t_coord), 1);
	if (enemy->last_coord == NULL)
		error_msg("Error: Memory enemy->last_coord", game);
	ft_lstadd_back(&game->enemies, ft_lstnew(enemy));
}
