NAME := libftprintf.a
LIBFT_DIR := ./libft
LIBFT_NAME   = $(LIBFT_DIR)/libft.a

SOURCES := \
	ft_nbrlen.c \
	ft_puthex.c \
	ft_putunbr.c \
	ft_printf.c \
	ft_printf_c_spec.c \
	ft_printf_s_spec.c \
	ft_printf_percent_spec.c \
	ft_printf_di_spec.c \
	ft_printf_u_spec.c \
	ft_printf_p_spec.c \
	ft_printf_x_spec.c \
	ft_printf_ux_spec.c \
	ft_handle_char_specs.c \
	ft_handle_num_specs.c \
	ft_handle_mem_specs.c \
	ft_handle_conv_specs.c \

OBJECTS := $(SOURCES:%.c=%.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_NAME)
#! DELETE BEFORE PUSH
	make -C $(LIBFT_DIR)
	ar -x $(LIBFT_NAME)
	ar -rcs $@ $(OBJECTS) *.o

#! DELETE BEFORE PUSH
ft_printf: $(OBJECTS) $(LIBFT_NAME)
	$(CC) -o $@ $^ -L $(LIBFT_DIR) -lft

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	#! DELETE BEFORE PUSH
	rm -rf *.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all