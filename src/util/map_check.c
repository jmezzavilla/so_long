/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:37:06 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 22:55:23 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_format(t_map *map)
{
	return (map->height != map->width);
}

int	valid_map_character(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_strchr("PCEM01", map->matrix[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_map_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		if (map->matrix[0][x] != '1' || map->matrix[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < map->height)
	{
		if (map->matrix[y][0] != '1' || map->matrix[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	valid_collectible_blocked(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] == 'C' && map->matrix[y][x + 1] == '1'
				&& map->matrix[y][x - 1] == '1' && map->matrix[y - 1][x] == '1'
				&& map->matrix[y + 1][x] == '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	valid_map(t_game *game)
{
	if (!valid_map_format(game->map))
		error_msg("Error: Error map format");
	if (!valid_map_character(game->map))
		error_msg("Error: Error map character");
	if (!valid_map_wall(game->map))
		error_msg("Error: Error map wall");
	if (!(game->nbr_exit == 1 && game->nbr_player == 1 && game->total_collectibles > 0))
		error_msg("Error: Error number of components");
	if (!valid_collectible_blocked(game->map))
		error_msg("Error: Error collectible blocked");
}
