/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:27:56 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/23 23:25:33 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_item(t_game *game)
{
	t_list			*lst;
	t_collectible	*collectible;
	int				y;
	int				x;

	lst = game->collectibles;
	y = game->player->coord->y / BLOCK_PIXEL;
	x = game->player->coord->x / BLOCK_PIXEL;
	if (game->map->matrix[y][x] == 'C')
	{
		while (lst)
		{
			collectible = (t_collectible *)lst->content;
			if (collectible->coord->x == game->player->coord->x
				&& collectible->coord->y == game->player->coord->y
				&& collectible->is_collected == 0)
			{
				collectible->is_collected = 1;
				game->total_collectibles--;
			}
			lst = lst->next;
		}
	}
}

t_buffer	*get_collectible_sprite(t_collectible *collectible, t_game *game)
{
	if (collectible->animation_pos == 4)
	{
		if (collectible->animation == C_END)
		{
			collectible->animation = C_START;
		}
		else
			collectible->animation += 1;
		collectible->animation_pos = 0;
	}
	else
		collectible->animation_pos++;
	return (&game->sprites->collectible[collectible->animation]);
}

void	draw_collectible(t_game *game)
{
	t_list			*lst;
	t_collectible	*collectible;

	lst = game->collectibles;
	while (lst)
	{
		collectible = (t_collectible *)lst->content;
		if (collectible->is_collected == 0)
		{
			draw(collectible->coord->x / BLOCK_PIXEL, collectible->coord->y
				/ BLOCK_PIXEL, get_collectible_sprite(collectible, game),
				game);
		}
		lst = lst->next;
	}
}
