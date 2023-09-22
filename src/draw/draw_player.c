/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:15 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 19:23:07 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_count_steps(t_game *game)
{
	char	*steps;
	char	*steps_window;

	steps = ft_itoa(game->player->steps);
	steps_window = ft_strjoin("steps: ", steps);
	free(steps);
	mlx_string_put(game->mlx, game->window, (game->map->width * BLOCK_PIXEL)
		- BLOCK_PIXEL * 2, game->map->height + BLOCK_PIXEL / 2, 0x0000000,
		steps_window);
	free(steps_window);
}

t_buffer	*get_player_sprite(t_game *game)
{
	static int	arr_pos;
	static int	anim_inter;

	if (anim_inter == 20)
	{
		if (game->player->coord->y != game->player->last_coord->y
			|| game->player->coord->x != game->player->last_coord->x)
			arr_pos = player_walk_sprite(game);
		anim_inter = 0;
	}
	else
		anim_inter++;
	return (&game->sprites->player[arr_pos]);
}

void	ft_die(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;

	lst = game->enemies;
	while (lst)
	{
		enemy = (t_enemy *)lst->content;
		if (enemy->coord->x == game->player->coord->x
			&& enemy->coord->y == game->player->coord->y)
		{
			msg("Game Over, RIP :(");
			end_game(game);
		}
		lst = lst->next;
	}
}

void	draw_player(t_game *game)
{
	ft_die(game);
	draw_count_steps(game);
	draw(game->player->coord->x / BLOCK_PIXEL, game->player->coord->y
		/ BLOCK_PIXEL, get_player_sprite(game), game);
}
