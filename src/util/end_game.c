/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:55:56 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/21 20:19:33 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	destroy_game(game);
	mlx_loop_end(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}
