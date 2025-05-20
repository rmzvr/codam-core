NAME := cub3D

LIBFT_DIR := ./libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

MLX_LINUX_DIR := ./mlx_linux
MLX_LINUX_NAME := $(MLX_LINUX_DIR)/libmlx_Linux.a

SOURCES :=         \
	main.c          \

OBJECTS := $(SOURCES:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -I/usr/include -Imlx_linux -I$(LIBFT_DIR) -O3

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(MLX_LINUX_NAME) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT_NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(MLX_LINUX_NAME):
	make -C $(MLX_LINUX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_LINUX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
