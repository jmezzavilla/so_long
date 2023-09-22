/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:40 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/22 23:21:44 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "constants.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map
{
	char		**matrix;
	t_list		*lst_map;
	int			height;
	int			width;
}				t_map;

typedef struct s_floodfill
{
	char		**map;
	int			total_collectibles;
	int			nbr_exit;
}				t_floodfill;

typedef struct s_exit
{
	t_coord		*coord;
}				t_exit;

typedef struct s_buffer
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_buffer;

typedef struct s_sprites
{
	t_buffer	player[TOTAL_SPRITE_PLAYER];
	t_buffer	collectible[TOTAL_SPRITE_COLLECTIBLE];
	t_buffer	enemy[TOTAL_SPRITE_ENEMY];
	t_buffer	tiles[TOTAL_SPRITE_TILES];
	t_buffer	exit[TOTAL_SPRITE_EXIT];
}				t_sprites;

typedef struct s_enemy
{
	int			animation;
	int			animation_pos;
	int			last_move;
	t_coord		*coord;
	t_coord		*last_coord;
}				t_enemy;

typedef struct s_collectible
{
	int			animation;
	int			animation_pos;
	int			is_collected;
	t_coord		*coord;
}				t_collectible;

typedef struct s_player
{
	int			animation;
	t_coord		*coord;
	t_coord		*last_coord;
	int			steps;
}				t_player;

typedef struct s_game
{
	t_map		*map;
	t_floodfill	*flood_fill;
	t_list		*enemies;
	t_list		*collectibles;
	t_player	*player;
	t_exit		*exit;
	t_sprites	*sprites;
	void		*mlx;
	void		*window;
	t_buffer	image_buffer;
	int			exit_animation;
	int			exit_animation_pos;
	int			total_collectibles;
	int			nbr_player;
	int			nbr_exit;
}				t_game;

int				so_long(char *map);

void			build(char *map, t_game *game);
void			build_map(char *path, t_game *game);
void			build_sprites(t_game *game);
void			build_player(t_game *game, t_coord *coord);
void			build_enemy(t_game *game, t_coord *coord);
void			build_collectible(t_game *game, t_coord *coord);
void			build_exit(t_game *game, t_coord *coord);
void			valid_map(t_game *game);

void			register_hook(t_game *game);

void			finish_game(t_game *game);
void			get_item(t_game *game);
void			move_player(int keycode, t_game *game);
void			move_enemy(t_game *game);
void			player_stop(t_game *game);

void			draw_player(t_game *game);
void			draw_background(t_game *game);
void			draw_wall(t_game *game);
void			draw_enemy(t_game *game);
void			draw_collectible(t_game *game);
void			draw_exit(t_game *game);

void			draw(int x, int y, t_buffer *sprite, t_game *game);

int				player_walk_sprite(t_game *game);

// check colision
int				is_down_wall(t_game *game, t_coord *coord);
int				is_up_wall(t_game *game, t_coord *coord);
int				is_left_wall(t_game *game, t_coord *coord);
int				is_right_wall(t_game *game, t_coord *coord);
void			move_down(t_game *game, t_coord *coord, t_coord *last_coord,
					int is_player);
void			move_up(t_game *game, t_coord *coord, t_coord *last_coord,
					int is_player);
void			move_left(t_game *game, t_coord *coord, t_coord *last_coord,
					int is_player);
void			move_right(t_game *game, t_coord *coord, t_coord *last_coord,
					int is_player);

void			end_game(t_game *game);
void			destroy_game(t_game *game);

void			error_msg(const char *message, t_game *game);
void			msg(const char *message);

#endif
