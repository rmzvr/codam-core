LIBFT_DIR := ./libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

NAME := push_swap

SOURCES := \
	main.c \
	swap.c \
	push.c \
	rotate.c \
	utils.c \
	validation.c \
	init.c \
	sort.c \
	list_utils.c \
	radix_sort.c \
	five_sort.c \
	stack_utils.c \

OBJECTS := $(SOURCES:.c=.o)

CC := cc
FLAGS := -Wall -Wextra -Werror


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_NAME) -o $(NAME)

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
