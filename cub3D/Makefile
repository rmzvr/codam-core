# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 13:56:28 by rzvir             #+#    #+#              #
#    Updated: 2025/07/24 14:14:10 by rzvir            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

INCLUDES_PATH =	includes/
SOURCES_PATH =	sources/

INCLUDES_BONUS_PATH =	includes_bonus/
SOURCES_BONUS_PATH =	sources_bonus/

BUILD_PATH =	build/
LIBS_PATH =		libs/

LIBFT_PATH =	$(LIBS_PATH)libft
LIBFT_INCLUDE_PATH = $(LIBS_PATH)libft/include
LIBFT =			$(LIBFT_PATH)/libft.a

MLX_LINUX_PATH := $(LIBS_PATH)mlx_linux
MLX_LINUX := $(MLX_LINUX_PATH)/libmlx_Linux.a

SRCS := \
	main.c \
	hooks.c \
	hooks_focus.c \
	utils.c \
	file.c \
	initializers/ray.c \
	initializers/wall.c \
	initializers/window.c \
	initializers/player.c \
	initializers/textures.c \
	movement/move.c \
	movement/rotation.c \
	movement/controls.c \
	drawer/line.c \
	drawer/stripe.c \
	drawer/frame.c \
	drawer/draw_elements.c \
	parser/lexer/lexer.c\
	parser/lexer/peek.c\
	parser/lexer/token.c\
	parser/lexer/word.c\
	parser/ast/parser.c\
	parser/ast/root.c\
	parser/ast/root_header.c\
	parser/ast/root_header_identifier.c\
	parser/ast/root_map.c\
	parser/ast/root_map_line.c\
	parser/ast/root_map_spawn.c\
	parser/ast/color.c\
	parser/ast/texture.c\
	parser/ast/skip.c\
	parser/dfs/dfs.c\
	parser/dfs/dfs_visit.c\
	parser/dfs/dfs_copy_map.c

SRCS_BONUS := \
	main_bonus.c \
	hooks_bonus.c \
	hooks_focus_bonus.c \
	utils_bonus.c \
	file_bonus.c \
	initializers/ray_bonus.c \
	initializers/wall_bonus.c \
	initializers/window_bonus.c \
	initializers/player_bonus.c \
	initializers/textures_bonus.c \
	minimap/tile_bonus.c \
	minimap/player_bonus.c \
	minimap/minimap_bonus.c \
	movement/move_bonus.c \
	movement/rotation_bonus.c \
	movement/controls_bonus.c \
	drawer/line_bonus.c \
	drawer/stripe_bonus.c \
	drawer/frame_bonus.c \
	drawer/draw_elements_bonus.c \
	parser/lexer/lexer_bonus.c\
	parser/lexer/peek_bonus.c\
	parser/lexer/token_bonus.c\
	parser/lexer/word_bonus.c\
	parser/ast/parser_bonus.c\
	parser/ast/root_bonus.c\
	parser/ast/root_header_bonus.c\
	parser/ast/root_header_identifier_bonus.c\
	parser/ast/root_map_bonus.c\
	parser/ast/root_map_line_bonus.c\
	parser/ast/root_map_spawn_bonus.c\
	parser/ast/color_bonus.c\
	parser/ast/texture_bonus.c\
	parser/ast/skip_bonus.c\
	parser/dfs/dfs_bonus.c\
	parser/dfs/dfs_visit_bonus.c\
	parser/dfs/dfs_copy_map_bonus.c

OBJS := $(SRCS:%.c=%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

OBJECTS = $(addprefix $(BUILD_PATH), $(OBJS))
OBJECTS_BONUS = $(addprefix $(BUILD_PATH), $(OBJS_BONUS))

CFLAGS :=	-Wall -Wextra -Werror -g -O3 -I/usr/include -fPIE -I$(MLX_LINUX_PATH) -I$(INCLUDES_PATH) -I$(LIBFT_INCLUDE_PATH)

all: $(LIBFT) $(NAME)

ifdef BONUS
$(NAME): $(LIBFT) $(MLX_LINUX) $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(LIBFT) -L$(MLX_LINUX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $@
else
$(NAME): $(LIBFT) $(MLX_LINUX) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -L$(MLX_LINUX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $@
endif

bonus:
	$(MAKE) BONUS=1 all

ifdef BONUS
CFLAGS += -I$(INCLUDES_BONUS_PATH)
$(BUILD_PATH)%.o: $(SOURCES_BONUS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
else
$(BUILD_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
endif

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX_LINUX):
	make -C $(MLX_LINUX_PATH)

clean:
	rm -rf $(BUILD_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@mkdir $(BUILD_PATH)

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
