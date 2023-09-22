/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:49:24 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 22:01:37 by jealves-         ###   ########.fr       */
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
	free(enemy);
	enemy = NULL;
}

void	clean_collectible(void *item)
{
	t_collectible	*collectible;

	collectible = (t_collectible *)item;
	free(collectible->coord);
	collectible->coord = NULL;
	free(collectible);
	collectible = NULL;
}

void	destroy_game(t_game *game)
{
	ft_lstclear(&game->map->lst_map, clean_lst);
	ft_cleanup_split(game->map->matrix, ft_strlen_matrix(game->map->matrix));
	ft_lstclear(&game->enemies, clean_enemy);
	ft_lstclear(&game->collectibles, clean_collectible);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->window);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
}

void	end_game(t_game *game)
{
	if (game)
		destroy_game(game);
	exit(EXIT_SUCCESS);
}
