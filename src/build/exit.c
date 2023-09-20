/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:07:11 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:31:57 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_coord_exit(t_game *game)
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
			if (game->map->matrix[y][x] == 'E')
			{
				game->exit->coord->x = (BLOCK_PIXEL * x);
				game->exit->coord->y = (BLOCK_PIXEL * y);
				game->nbr_exit++;
			}
			x++;
		}
		y++;
	}
}

void	build_exit(t_game *game)
{
	game->exit = ft_calloc(sizeof(t_exit), 1);
	if (game->exit == NULL)
		error_msg("Error: memory game->exit");
	game->exit->coord = ft_calloc(sizeof(t_coord), 1);
	if (game->exit->coord == NULL)
		error_msg("Error: memory game->exit->coord");
	build_coord_exit(game);
}
