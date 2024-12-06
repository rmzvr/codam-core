NAME := fractol
LIBFT_DIR := ./libft
LIBFT_NAME   = $(LIBFT_DIR)/libft.a

SOURCES := \
	main.c \
	fractol.c \
	cleanup.c \
	pixel_put.c \
	calculate_color.c \
	scale_down_num.c \
	shape_checking.c \
	handle_controls.c \
	render_mandelbrot_fractal.c \
	render_julia_fractal.c \
	render_mandelbrot_julia_set.c \

OBJECTS := $(SOURCES:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -g -O3 -I/usr/include -Imlx_linux -I$(LIBFT_DIR)

$(NAME): $(LIBFT_NAME) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT_NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
