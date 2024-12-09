NAME := fractol
LIBFT_DIR := ./libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a
MLX_LINUX_DIR := ./mlx_linux
MLX_LINUX_NAME := $(MLX_LINUX_DIR)/libmlx_Linux.a

SOURCES :=           \
    init.c            \
    main.c            \
    hooks.c           \
    render.c          \
    ft_atof.c         \
    cleanup.c         \
    pixel_put.c       \
    shape_checking.c  \
    calculate_color.c \
    transform_utils.c \
    validate_arguments.c \
    show_help_and_exit.c \
    render_julia_fractal.c \
    render_mandelbrot_fractal.c

OBJECTS := $(SOURCES:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -g -O3 -I/usr/include -Imlx_linux -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(MLX_LINUX_NAME) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT_NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

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
