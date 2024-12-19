NAME := pipex

LIBFT_DIR := ./libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

SOURCES :=         \
	main.c          \
	get_next_line/get_next_line.c          \
	get_next_line/get_next_line_utils.c          \

OBJECTS := $(SOURCES:%.c=%.o)

all: $(NAME)

#! REMOVE -w
$(NAME): $(LIBFT_NAME) $(MLX_LINUX_NAME) $(OBJECTS)
	$(CC) -w $(OBJECTS) $(LIBFT_NAME) -o $@

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
