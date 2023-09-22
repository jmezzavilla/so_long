/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:56:05 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 22:46:21 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_player(t_game *game, t_coord *coord)
{
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->coord = coord;
	game->player->last_coord = ft_calloc(sizeof(t_coord), 1);
	if (game->player->last_coord == NULL)
		error_msg("Error: memory player->last_coord", game);
	game->nbr_player++;
}

void	build_exit(t_game *game, t_coord *coord)
{
	game->exit = ft_calloc(sizeof(t_exit), 1);
	if (game->exit == NULL)
		error_msg("Error: Memory game->exit", game);
	game->exit->coord = coord;
	game->nbr_exit++;
}

void	build_collectible(t_game *game, t_coord *coord)
{
	t_collectible	*collectible;

	collectible = ft_calloc(sizeof(t_collectible), 1);
	if (collectible == NULL)
		error_msg("Error: Memory collectible", game);
	collectible->coord = coord;
	collectible->is_collected = 0;
	game->total_collectibles++;
	if (game->collectibles == NULL)
		game->collectibles = ft_lstnew(collectible);
	else
		ft_lstadd_front(&game->collectibles, ft_lstnew(collectible));
}

void	build_enemy(t_game *game, t_coord *coord)
{
	t_enemy	*enemy;

	enemy = ft_calloc(sizeof(t_enemy), 1);
	if (enemy == NULL)
		error_msg("Error: Memory enemy", game);
	enemy->coord = coord;
	enemy->last_coord = ft_calloc(sizeof(t_coord), 1);
	if (enemy->last_coord == NULL)
		error_msg("Error: Memory enemy->last_coord", game);
	if (game->enemies == NULL)
		game->enemies = ft_lstnew(enemy);
	else
		ft_lstadd_front(&game->enemies, ft_lstnew(enemy));
}
