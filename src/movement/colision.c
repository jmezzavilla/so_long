/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:54:21 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 18:49:10 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_right_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = coord->y / BLOCK_PIXEL;
	x = (coord->x + BLOCK_PIXEL) / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_left_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = coord->y / BLOCK_PIXEL;
	x = (coord->x - BLOCK_PIXEL) / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_up_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = (coord->y - BLOCK_PIXEL) / BLOCK_PIXEL;
	x = coord->x / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_down_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = ((coord->y + BLOCK_PIXEL) / BLOCK_PIXEL);
	x = coord->x / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}
