NAME := cub3D

INCLUDES_PATH =	includes/
SOURCES_PATH =	sources/

BUILD_PATH =	build/
LIBS_PATH =		libs/

LIBFT_PATH =	$(LIBS_PATH)libft
LIBFT =			$(LIBFT_PATH)/libft.a

MLX_LINUX_PATH := $(LIBS_PATH)mlx_linux
MLX_LINUX := $(MLX_LINUX_PATH)/libmlx_Linux.a

SRCS := \
	main.c \
	line.c \
	player.c \
	map_data.c \
	helpers.c \
	cleaners.c \
	initializers.c \
	minimap/map.c \
	minimap/ray.c \
	minimap/player.c \
	raycasting/dda.c \
	raycasting/ray.c \
	raycasting/wall.c \
	raycasting/draw.c \
	raycasting/init.c \

OBJS :=		$(SRCS:.c=.o)

SOURCES = 		$(addprefix $(SOURCES_PATH), $(SRCS))
OBJECTS = 		$(addprefix $(BUILD_PATH), $(OBJS))

CFLAGS :=	-Wall -Wextra -Werror -I/usr/include -fPIE -I$(MLX_LINUX_PATH) -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -O3

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(MLX_LINUX) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -L$(MLX_LINUX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $@

$(BUILD_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

$(MLX_LINUX):
	make -C $(MLX_LINUX_PATH)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@mkdir $(BUILD_PATH)

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
