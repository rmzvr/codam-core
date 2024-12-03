NAME := fractol

SOURCES := \
	fractol.c \
	cleanup.c \
	pixel_put.c \
	calculate_color.c \
	scale_down_range.c \
	shape_checking.c \
	handle_controls.c \
	render_mandelbrot_fractal.c \
	render_julia_fractal.c \
	# render_fractol_with_exterior_distance_estimation_coloring.c \

OBJECTS := $(SOURCES:%.c=%.o)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@


all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
