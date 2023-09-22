/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:02:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 18:40:39 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *map)
{
	t_game	game;

	build(map, &game);
	register_hook(&game);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (so_long(av[1]));
	else
		error_msg("Error: Invalid Number of Arguments", NULL);
}
