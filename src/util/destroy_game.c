/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:49:24 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/26 21:41:52 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_lst(void *item)
{
	if (item)
		free(item);
}

void	clean_enemy(void *item)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)item;
	free(enemy->coord);
	free(enemy->last_coord);
	enemy->coord = NULL;
	enemy->last_coord = NULL;
	if (enemy)
		free(enemy);
}

void	clean_collectible(void *item)
{
	t_collectible	*collectible;

	collectible = (t_collectible *)item;
	free(collectible->coord);
	collectible->coord = NULL;
	if (collectible)
		free(collectible);
}

void	destroy_game(t_game *game)
{
	ft_lstclear(&game->map->lst_map, clean_lst);
	ft_lstclear(&game->enemies, clean_enemy);
	ft_lstclear(&game->collectibles, clean_collectible);
}

void	end_game(t_game *game)
{
	if (game)
		destroy_game(game);
	exit(EXIT_SUCCESS);
}
