/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:15 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:33:55 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_sprite_pos(t_game *game)
{
	if (game->player->coord->y != game->player->last_coord->y
		|| game->player->coord->x != game->player->last_coord->x)
		return (player_walk_sprite(game));
	return (-1);
}

int	*get_player_sprite(t_game *game)
{
	static int	arr_pos;
	static int	anim_inter;
	int			pos;

	if (anim_inter == 20)
	{
		anim_inter = 0;
		pos = player_sprite_pos(game);
		if (pos != -1)
			arr_pos = pos;
	}
	else
		anim_inter++;
	return (game->sprites->player[arr_pos]);
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
			game->end_game = -1;
		}
		lst = lst->next;
	}
}

void	draw_player(t_game *game)
{
	ft_die(game);
	draw_count_steps(game);
	mlx_put_image_to_window(game->mlx, game->window, get_player_sprite(game),
		game->player->coord->x, game->player->coord->y);
}
