NAME := libftprintf.a

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
	ar -rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all