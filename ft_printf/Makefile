NAME := libftprintf.a
LIBFT_DIR := ./libft
LIBFT_NAME   = $(LIBFT_DIR)/libft.a

SOURCES := \
	ft_printf.c \
	ft_put_unum.c \
	ft_handle_conv_specs.c \
	ft_handle_char_specs.c \
	ft_handle_num_specs.c \
	ft_handle_mem_specs.c \

OBJECTS := $(SOURCES:%.c=%.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	mv ./libft/libft.a ./$@
	ar -rcs $@ $(OBJECTS)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all