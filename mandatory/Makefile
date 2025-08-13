# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 06:04:01 by mdegache          #+#    #+#              #
#    Updated: 2025/08/13 14:29:57 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[31m
GREEN=\033[32m
PURPLE=\033[35m
RESET=\033[0m

MLXDIR = includes/MacroLibX
MLX_STATIC = $(MLXDIR)/libmlx_Linux.a
MLX_SHARED = $(MLXDIR)/libmlx.so
LIBMLX = $(MLX_SHARED) -lSDL2
NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lSDL2
LMFLAGS = -lm

LIB = includes/libft
LIBFT = includes/libft/libft.a includes/MacroLibX/libmlx.so

SRC = 	src/main.c\
		src/game/cub3d.c\
		src/game/draw_map.c\
		src/parsing/parsing.c\
		src/parsing/parsing_map.c\
		src/window/Keybord.c\
		src/window/events.c\
		src/window/raycast.c\
		src/window/Texture.c\
		src/utils/get_next_line.c\
		src/utils/utils_parsing.c\
		src/utils/color.c\
		src/free/ft_free.c

OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(SRC) $(LIBFT) $(CFLAGS) $(LDFLAGS) $(LMFLAGS) $(LIBMLX) -o $(NAME)
	@echo "$(GREEN)SUCCESS$(RESET)"

$(MLX):
	@$(MAKE) -C $(MLXDIR) -s

$(LIBFT):
	@$(MAKE) -C $(LIB) bonus -s 
	@$(MAKE) -C $(MLXDIR) -s

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIB) clean
	@$(MAKE) -s -C $(MLXDIR) clean
	@echo "$(PURPLE)CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIB) fclean
	@$(MAKE) -s -C $(MLXDIR) fclean
	@echo "$(RED)FCLEAN$(RESET)"

re: fclean all

.PHONY : all clean fclean re