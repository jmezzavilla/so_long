/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:48:46 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/21 20:20:41 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			draw(x, y, &game->sprites->tiles[0], game);
			x++;
		}
		y++;
	}
}

void	draw_count_steps(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->player->steps);
	mlx_string_put(game->mlx, game->window, (game->map->width * BLOCK_PIXEL)
		- BLOCK_PIXEL * 2, game->map->height + BLOCK_PIXEL / 2, 00001111,
		ft_strjoin("steps: ", steps));
}
