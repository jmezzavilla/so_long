/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:27:09 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/23 21:56:34 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_game *game)
{
	char	*line;

	line = NULL;
	game->map = ft_calloc(sizeof(t_map), 1);
	game->map->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->map->width == 0)
			game->map->width = ft_strlen_nl(line);
		else if (game->map->width != (int)ft_strlen_nl(line))
			error_msg("Error: Invalid map, wrong size", NULL);
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
		error_msg("Error: Memory game->map->matrix[][]", game);
	game->flood_fill->map = ft_calloc(sizeof(char *), game->map->height);
	if (!game->flood_fill->map)
		error_msg("Error: Memory game->flood_fill->map[][]", game);
	while (lst)
	{
		game->map->matrix[i] = ft_strdup(lst->content);
		game->flood_fill->map[i] = ft_strdup(lst->content);
		if (!game->map->matrix[i] || !game->flood_fill->map[i])
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
	if (ft_strcmp(extension, BER) != 0)
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
		error_msg("Error: Map not found", NULL);
	read_map(fd, game);
	close(fd);
	game->flood_fill = ft_calloc(sizeof(t_floodfill), 1);
	if (!game->flood_fill)
		error_msg("Error: memory game->flood_fill", game);
	convert_lst_to_char(game);
}
