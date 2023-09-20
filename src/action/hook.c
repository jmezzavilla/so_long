/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:17:28 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:32:44 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == LETTER_KEY_EXIT)
	{
		select_option(game);
		game->end_game = -1;
	}
	else if (game->end_game == 0)
		move_player(keycode, game);
	return (0);
}

int	game_end_options(int key, t_game *game)
{
	if (key == LETTER_KEY_DOWN || key == ARROW_KEY_DOWN)
		put_arrows(game, LETTER_KEY_DOWN);
	if (key == LETTER_KEY_UP || key == ARROW_KEY_UP)
		put_arrows(game, LETTER_KEY_UP);
	if (key == KEY_ENTER)
	{
		if (game->arrow_position == LETTER_KEY_UP)
			so_long(game->map->map_path);
		else if (game->arrow_position == LETTER_KEY_DOWN)
		{
			end_game(game);
		}
	}
	return (0);
}

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keydown, game);
	mlx_key_hook(game->window, game_end_options, game);
}
