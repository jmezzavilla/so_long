/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:49:24 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 17:50:57 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game, t_buffer *sprites, int total_sprite)
{
	int	i;

	i = 0;
	while (i < total_sprite)
	{
		if (sprites[i].img)
		{
			mlx_destroy_image(game->mlx, sprites[i].img);
			sprites[i].img = NULL;
		}
		i++;
	}
}

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
	/*destroy_images(game, game->sprites->player, TOTAL_SPRITE_PLAYER);
	destroy_images(game, game->sprites->enemy, TOTAL_SPRITE_ENEMY);
	destroy_images(game, game->sprites->collectible, TOTAL_SPRITE_COLLECTIBLE);
	destroy_images(game, game->sprites->tiles, TOTAL_SPRITE_TILES);
	destroy_images(game, game->sprites->exit, TOTAL_SPRITE_EXIT);*/
	if(game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->sprites);
	game->sprites = NULL;
	ft_lstclear(&game->map->lst_map, clean_lst);
	game->map->matrix = ft_cleanup_split(game->map->matrix,
			ft_strlen_matrix(game->map->matrix));
	free(game->map);
	game->map = NULL;
	ft_lstclear(&game->enemies, clean_enemy);
	ft_lstclear(&game->collectibles, clean_collectible);
	free(game->player->last_coord);
	game->player->last_coord = NULL;
	free(game->player->coord);
	game->player->coord = NULL;
	free(game->player);
	game->player = NULL;
}
