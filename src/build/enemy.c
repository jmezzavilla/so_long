/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:55:53 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:25:17 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_enemy(t_game *game, int y, int x)
{
	t_enemy	*enemy;

	enemy = ft_calloc(sizeof(t_enemy), 1);
	if (enemy == NULL)
		error_msg("Error: memory enemy");
	enemy->coord = ft_calloc(sizeof(t_coord), 1);
	if (enemy->coord == NULL)
		error_msg("Error: memory enemy->coord");
	enemy->last_coord = ft_calloc(sizeof(t_coord), 1);
	if (enemy->last_coord == NULL)
		error_msg("Error: memory enemy->last_coord");
	enemy->coord->x = x * BLOCK_PIXEL;
	enemy->coord->y = y * BLOCK_PIXEL;
	if (game->enemies == NULL)
		game->enemies = ft_lstnew(enemy);
	else
		ft_lstadd_front(&game->enemies, ft_lstnew(enemy));
}

void	build_enemies(t_game *game)
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
			if (game->map->matrix[y][x] == 'M')
			{
				create_enemy(game, y, x);
			}
			x++;
		}
		y++;
	}
}
