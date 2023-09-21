/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:17:28 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/21 20:20:21 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == LETTER_KEY_EXIT)
	{
		exit(0);
		//select_option(game);
		//game->end_game = -1;
	}
	else if (game->end_game == 0)
		move_player(keycode, game);
	return (0);
}

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keydown, game);
}
