NAME := libftprintf.a
# LIBFT_DIR := ./libft
# LIBFT_NAME   = $(LIBFT_DIR)/libft.a

SOURCES := \
	ft_printf.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_printf_X.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c

OBJECTS := $(SOURCES:%.c=%.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

#! DELETE BEFORE PUSH
ft_printf: $(OBJECTS)
	$(CC) -o $@ $^

# $(LIBFT_NAME):
# 	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	# make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	# make -C $(LIBFT_DIR) fclean

re: fclean all
