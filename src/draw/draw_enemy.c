/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:47:31 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 23:02:41 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_buffer	*get_enemy_sprite(t_enemy *enemy, t_game *game)
{
	if (enemy->animation == 50)
	{
		if (enemy->animation_pos == ENEMY_END)
		{
			enemy->animation_pos = ENEMY_START;
		}
		else
			enemy->animation_pos += 1;
		enemy->animation = 0;
	}
	else
		enemy->animation++;
	return (&game->sprites->enemy[enemy->animation_pos]);
}

void	draw_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;

	lst = game->enemies;
	while (lst)
	{
		enemy = (t_enemy *)lst->content;
		draw(
			enemy->coord->x / BLOCK_PIXEL,
			enemy->coord->y / BLOCK_PIXEL,
			get_enemy_sprite(enemy, game),
			game);
		lst = lst->next;
	}
}
