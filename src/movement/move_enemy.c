/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:48:06 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:36:12 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->coord->x < (game->map->width * BLOCK_PIXEL) 
		&& !is_right_wall(game, enemy->coord))
	{
		enemy->last_coord->x = enemy->coord->x;
		enemy->coord->x += BLOCK_PIXEL;
	}
}

void	move_left_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->coord->x > 1 && !is_left_wall(game, enemy->coord))
	{
		enemy->last_coord->x = enemy->coord->x;
		enemy->coord->x -= BLOCK_PIXEL;
	}
}

void	move_up_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->coord->y > 1 && !is_up_wall(game, enemy->coord))
	{
		enemy->last_coord->y = enemy->coord->y;
		enemy->coord->y -= BLOCK_PIXEL;
	}
}

void	move_down_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->coord->y < (game->map->height * BLOCK_PIXEL) 
		&& !is_down_wall(game, enemy->coord))
	{
		enemy->last_coord->y = enemy->coord->y;
		enemy->coord->y += BLOCK_PIXEL;
	}
}

void	move_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;
	int		move;

	move = 0;
	lst = game->enemies;
	while (lst)
	{
		enemy = ((t_enemy *)lst->content);
		move = rand() % 450;
		if (move == 1)
			move_left_enemy(game, enemy);
		else if (move == 2)
			move_right_enemy(game, enemy);
		else if (move == 3)
			move_up_enemy(game, enemy);
		else if (move == 4)
			move_down_enemy(game, enemy);
		if (!enemy && !game)
			return ;
		enemy->last_move = move;
		lst = lst->next;
	}
}
