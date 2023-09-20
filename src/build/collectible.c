/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:55:50 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:24:30 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_collectible(t_game *game, int y, int x)
{
	t_collectible	*collectible;

	collectible = ft_calloc(sizeof(t_collectible), 1);
	if (collectible == NULL)
		error_msg("Error: memory collectible");
	collectible->coord = ft_calloc(sizeof(t_coord), 1);
	if (collectible->coord == NULL)
		error_msg("Error: memory collectible->coord");
	collectible->coord->x = x * BLOCK_PIXEL;
	collectible->coord->y = y * BLOCK_PIXEL;
	collectible->is_collected = 0;
	game->total_collectibles++;
	if (game->collectibles == NULL)
		game->collectibles = ft_lstnew(collectible);
	else
		ft_lstadd_front(&game->collectibles, ft_lstnew(collectible));
}

void	build_collectibles(t_game *game)
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
			if (game->map->matrix[y][x] == 'C')
			{
				create_collectible(game, y, x);
			}
			x++;
		}
		y++;
	}
}
