# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 00:18:43 by jealves-          #+#    #+#              #
#    Updated: 2023/11/21 22:18:04 by jealves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =		src/action/hook.c\
			src/build/game.c\
			src/build/characters.c\
			src/build/map.c\
			src/build/sprites.c\
			src/draw/draw_background.c\
			src/draw/draw_collectible.c\
			src/draw/draw_enemy.c\
			src/draw/draw_exit.c\
			src/draw/draw_player_movement.c\
			src/draw/draw_player.c\
			src/draw/draw_pixels.c\
			src/util/destroy_game.c\
			src/util/msg.c\
			src/util/map_check.c\
			src/so_long.c\
			src/movement/direction.c\
			src/movement/colision.c\

PROJECT = <$(GREEN)$(NAME)$(RESET)>
			
INCLUDES = include
# Contains the X11 and MLX header files
INCLUDES_MLX = -I/usr/include -Imlx

# Link X11 and MLX
MLX_DIR = ../mlx

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

DIR_LIBFT = libft
INCLUDE_LIB = $(DIR_LIBFT)/include
LIB = $(DIR_LIBFT)/libft.a

CFLAGS = -g -Wall -I $(INCLUDES) -I $(INCLUDE_LIB) -I $(MLX_DIR) -Wextra -Werror -fsanitize=address
RM= rm -rf

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c
	@printf "$(PROJECT) compiling $(BLUE)$<$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES_MLX) -c $< -o $@

all : $(MLX_LIB) $(NAME)

lib : 
	@make -C $(DIR_LIBFT)

$(NAME) : lib $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(MLX_FLAGS)
	@printf "$(PROJECT) $(RED)compiled$(RESET)!\n"


$(MLX_LIB):
	@make -C $(MLX_DIR)


clean :
	$(RM) $(OBJ)
	make -C $(DIR_LIBFT)  clean
	@for file in $(OBJ); do \
        echo "$(PROJECT) deleting $(YELLOW) $$file $(RESET)!"; \
    done
	
fclean : clean
	$(RM) $(NAME)
	@printf "$(PROJECT) $(YELLOW) deleting $(NAME) $(RESET)!\n"
	make -C $(DIR_LIBFT) fclean
	
	
re : fclean all

.PHONY : all clean fclean bonus re

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m