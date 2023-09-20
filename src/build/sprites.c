/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:46:51 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 21:27:29 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*path_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin(SPRITE_PATH, sprite_name);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, nbr);
	free(str1);
	str1 = ft_strjoin(str2, XPM);
	free(str2);
	free(nbr);
	return (str1);
}

static void	load_sprite(t_game *game, char *sprite_type, char *path, int pos)
{
	int	pxl;

	if (ft_strcmp(sprite_type, PLAYER) == 0)
		game->sprites->player[pos] = mlx_xpm_file_to_image(game->mlx, path,
				&pxl, &pxl);
	else if (ft_strcmp(sprite_type, ENEMY) == 0)
		game->sprites->enemy[pos] = mlx_xpm_file_to_image(game->mlx, path, &pxl,
				&pxl);
	else if (ft_strcmp(sprite_type, COLLECTIBLE) == 0)
		game->sprites->collectible[pos] = mlx_xpm_file_to_image(game->mlx, path,
				&pxl, &pxl);
	else if (ft_strcmp(sprite_type, TILES) == 0)
		game->sprites->tiles[pos] = mlx_xpm_file_to_image(game->mlx, path, &pxl,
				&pxl);
	else if (ft_strcmp(sprite_type, EXIT) == 0)
		game->sprites->exit[pos] = mlx_xpm_file_to_image(game->mlx, path, &pxl,
				&pxl);
	else if (ft_strcmp(sprite_type, GAMEOVER) == 0)
		game->sprites->game_over[pos] = mlx_xpm_file_to_image(game->mlx, path,
				&pxl, &pxl);
}

static void	create_sprites(t_game *game, char *sprite_type, int nbr_sprites)
{
	char	*path;
	int		fd_xpm;
	int		i;

	i = 0;
	while (i < nbr_sprites)
	{
		path = path_sprite(sprite_type, i);
		fd_xpm = open(path, O_RDONLY);
		if (fd_xpm == -1)
		{
			error_msg(ft_strjoin("Error to open file: ", path));
		}
		close(fd_xpm);
		load_sprite(game, sprite_type, path, i);
		free(path);
		fd_xpm = -1;
		i++;
	}
}

void	build_sprites(t_game *game)
{
	game->sprites = ft_calloc(sizeof(t_sprites), 1);
	create_sprites(game, EXIT, TOTAL_SPRITE_EXIT);
	create_sprites(game, PLAYER, TOTAL_SPRITE_PLAYER);
	create_sprites(game, COLLECTIBLE, TOTAL_SPRITE_COLLECTIBLE);
	create_sprites(game, ENEMY, TOTAL_SPRITE_ENEMY);
	create_sprites(game, TILES, TOTAL_SPRITE_TILES);
	create_sprites(game, GAMEOVER, TOTAL_SPRITE_GAMEOVER);
}
