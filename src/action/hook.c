/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:17:28 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 19:19:19 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_game *game)
{
	move_enemy(game);
	draw_background(game);
	draw_wall(game);
	draw_collectible(game);
	draw_exit(game);
	draw_enemy(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0,0);
	draw_player(game);
	return (EXIT_SUCCESS);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == LETTER_KEY_EXIT)
	{
		msg("Don't give up, try again");
		end_game(game);
	}
	else
		move_player(keycode, game);
	return (0);
}

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->window, 17, 0, (void *) end_game, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
