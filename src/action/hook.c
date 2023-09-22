/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:17:28 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 23:08:19 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_game *game)
{
	move_enemy(game);
	draw_background(game);
	draw_collectible(game);
	draw_exit(game);
	draw_enemy(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0,
		0);
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
	{
		if (keycode == LETTER_KEY_LEFT || keycode == ARROW_KEY_LEFT)
			move_left(game, game->player->coord, game->player->last_coord, 1);
		else if (keycode == LETTER_KEY_RIGHT || keycode == ARROW_KEY_RIGHT)
			move_right(game, game->player->coord, game->player->last_coord, 1);
		else if (keycode == LETTER_KEY_UP || keycode == ARROW_KEY_UP)
			move_up(game, game->player->coord, game->player->last_coord, 1);
		else if (keycode == LETTER_KEY_DOWN || keycode == ARROW_KEY_DOWN)
			move_down(game, game->player->coord, game->player->last_coord, 1);
		get_item(game);
		finish_game(game);
	}
	return (0);
}

int	closing_game(t_game *game)
{
	ft_printf("Exit %s\n", WINDOW_TITLE);
	end_game(game);
	return (0);
}

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->window, 17, 0, closing_game, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
