/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:47:31 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:36:48 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	draw_move_enemy(t_enemy *enemy)
{
	if (enemy->animation_pos == ENEMY_END)
	{
		enemy->animation_pos = ENEMY_START;
	}
	else
		enemy->animation_pos += 1;
	return (enemy->animation_pos);
}

int	*get_enemy_sprite(t_enemy *enemy, t_game *game)
{
	if (enemy->animation == 150)
	{
		enemy->animation = 0;
		draw_move_enemy(enemy);
	}
	else
		enemy->animation += 1;
	return (game->sprites->enemy[enemy->animation_pos]);
}

void	draw_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;

	lst = game->enemies;
	while (lst)
	{
		enemy = (t_enemy *)lst->content;
		mlx_put_image_to_window(game->mlx, game->window, get_enemy_sprite(enemy,
				game), enemy->coord->x, enemy->coord->y);
		lst = lst->next;
	}
}
