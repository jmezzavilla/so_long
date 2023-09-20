/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:40 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/20 18:47:26 by jealves-         ###   ########.fr       */
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
	char		**matrix_map;
	t_list		*lst_map;
	int			height;
	int			width;
	int			fd;
	char		*map_path;
}				t_map;

typedef struct s_exit
{
	t_coord		*coord;
}				t_exit;

typedef struct s_sprites
{
	void		*player[TOTAL_SPRITE_PLAYER];
	void		*collectible[TOTAL_SPRITE_COLLECTIBLE];
	void		*enemy[TOTAL_SPRITE_ENEMY];
	void		*tiles[TOTAL_SPRITE_TILES];
	void		*exit[TOTAL_SPRITE_EXIT];
	void		*game_over[TOTAL_SPRITE_GAMEOVER];
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
	t_list		*enemies;
	t_list		*collectibles;
	t_player	*player;
	t_exit		*exit;
	t_sprites	*sprites;
	void		*mlx;
	void		*window;
	int			exit_animation;
	int			exit_animation_pos;
	int			total_collectibles;
	int			end_game;
	int			arrow_position;
	int			nbr_player;
	int			nbr_exit;
}				t_game;

int				so_long(char *map);

void			build(char *map, t_game *game);
void			build_map(char *path, t_game *game);
void			build_sprites(t_game *game);
void			build_player(t_game *game);
void			build_enemies(t_game *game);
void			build_collectibles(t_game *game);
void			build_exit(t_game *game);
void			valid_map(t_game *game);

void			register_hook(t_game *game);

void			exit_game(t_game *game);
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
void			draw_count_steps(t_game *game);

void			draw(int x, int y, void *sprite, t_game *game);

int				player_walk_sprite(t_game *game);

// check colision
int				is_down_wall(t_game *game, t_coord *coord);
int				is_up_wall(t_game *game, t_coord *coord);
int				is_left_wall(t_game *game, t_coord *coord);
int				is_right_wall(t_game *game, t_coord *coord);

void			end_game(t_game *game);
void			destroy_game(t_game *game);
void			select_option(t_game *game);
void			put_arrows(t_game *game, int direction);
void			draw_map_game_over(t_game *game);

void			error_msg(const char *message);

#endif
