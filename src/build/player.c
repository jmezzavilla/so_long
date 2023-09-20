/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:56:05 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:32:24 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_coord_player(t_game *game)
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
			if (game->map->matrix[y][x] == 'P')
			{
				game->player->coord->x = (BLOCK_PIXEL * x);
				game->player->coord->y = (BLOCK_PIXEL * y);
				game->nbr_player++;
			}
			x++;
		}
		y++;
	}
}

void	build_player(t_game *game)
{
	game->player = ft_calloc(sizeof(t_player), 1);
	game->player->coord = ft_calloc(sizeof(t_coord), 1);
	if (game->player->coord == NULL)
		error_msg("Error: memory player->coord");
	game->player->last_coord = ft_calloc(sizeof(t_coord), 1);
	if (game->player->last_coord == NULL)
		error_msg("Error: memory player->last_coord");
	build_coord_player(game);
}
