/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:27:09 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 19:11:05 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	char	*line;

	line = NULL;
	game->map->width = -1;
	while (1)
	{
		line = get_next_line(game->map->fd);
		if (!line)
			break ;
		if (game->map->width == -1)
			game->map->width = ft_strlen(line) - 1;
		if (game->map->lst_map == NULL)
			game->map->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&game->map->lst_map, ft_lstnew(line));
	}
}

void	convert_lst_to_char(t_game *game)
{
	t_list	*lst;
	int		i;

	lst = game->map->lst_map;
	i = 0;
	game->map->height = ft_lstsize(game->map->lst_map);
	game->map->matrix = ft_calloc(game->map->height + 1, sizeof(char *));
	if (!game->map->matrix)
		error_msg("Error: memory game->map->matrix[][]", game);
	game->flood_fill->map = ft_calloc(sizeof(char *), game->map->height);
	if (!game->flood_fill->map)
		error_msg("Error: memory game->flood_fill->map[][]", game);
	while (lst)
	{
		game->map->matrix[i] = ft_strdup(lst->content);
		game->flood_fill->map[i] = ft_strdup(lst->content);
		if (!game->map->matrix[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
}

void	check_map_extension(char *path)
{
	char	*extension;

	extension = ft_strchr(path, '.');
	if (extension == NULL)
	{
		error_msg("Error: Map extension invalid", NULL);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(extension, ".ber") != 0)
	{
		error_msg("Error: Map extension invalid", NULL);
		exit(EXIT_FAILURE);
	}
}

void	build_map(char *path, t_game *game)
{
	int	fd;

	check_map_extension(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg("Error: Map not found", game);
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map)
		error_msg("Error: memory game->map", game);
	game->flood_fill = ft_calloc(sizeof(t_floodfill), 1);
	if (!game->flood_fill)
		error_msg("Error: memory game->flood_fill", game);
	game->map->map_path = path;
	game->map->fd = fd;
	read_map(game);
	close(fd);
	convert_lst_to_char(game);
}
