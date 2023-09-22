/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:39:49 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 17:47:26 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(const char *message, t_game *game)
{
	ft_printf("%s\n", message);
	end_game(game);
	exit(EXIT_FAILURE);
}

void	msg(const char *message)
{
	ft_printf("%s\n", message);
}
