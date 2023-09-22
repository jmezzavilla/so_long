/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:37:06 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 20:05:51 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (!ft_strchr("PCEM01\n", map->matrix[y][x]))
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

void	fill(int y, int x, t_game *game, char to_fill)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width
		|| game->flood_fill->map[y][x] == to_fill)
		return ;
	if (game->flood_fill->map[y][x] == 'C')
		game->flood_fill->total_collectibles++;
	if (game->flood_fill->map[y][x] == 'E')
		game->flood_fill->nbr_exit++;
	if (game->flood_fill->map[y][x] == '1')
		return ;
	game->flood_fill->map[y][x] = to_fill;
	fill(y + 1, x, game, to_fill);
	fill(y - 1, x, game, to_fill);
	fill(y, x + 1, game, to_fill);
	fill(y, x - 1, game, to_fill);
}

int	flood_fill(t_game *game)
{
	int	player_pos_x;
	int	player_pos_y;

	player_pos_x = game->player->coord->x / BLOCK_PIXEL;
	player_pos_y = game->player->coord->y / BLOCK_PIXEL;
	game->flood_fill->total_collectibles = 0;
	game->flood_fill->nbr_exit = 0;
	fill(player_pos_y, player_pos_x, game, 'A');
	ft_cleanup_split(game->flood_fill->map,
		ft_strlen_matrix(game->flood_fill->map));
	if (game->total_collectibles != game->flood_fill->total_collectibles
		|| game->nbr_exit != game->flood_fill->nbr_exit)
		return (0);
	return (1);
}

void	valid_map(t_game *game)
{
	if (game->map->height == game->map->width)
		error_msg("Error: Invalid format, wrong size", game);
	if (!valid_map_character(game->map))
		error_msg("Error: Invalid number of characters", game);
	if (!valid_map_wall(game->map))
		error_msg("Error: Missing wall", game);
	if (!(game->nbr_exit == 1 && game->nbr_player == 1
			&& game->total_collectibles > 0))
		error_msg("Error: Invalid number of Players/Exit/Collectibles", game);
	if (!flood_fill(game))
		error_msg("Error: Map not supported", game);
}
