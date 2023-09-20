/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:54:38 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/19 19:02:29 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(int x, int y, void *sprite, t_game *game)
{
	if (x < -BLOCK_PIXEL || y < -BLOCK_PIXEL || x > game->map->width
		|| y > game->map->height)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, sprite, x * BLOCK_PIXEL, y
		* BLOCK_PIXEL);
}

void	draw_map_game_over(t_game *game)
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
			game->map->matrix[y][x] = 'B';
			x++;
		}
		y++;
	}
}
