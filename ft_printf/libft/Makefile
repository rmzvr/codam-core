NAME := libft.a

SOURCES := \
	ft_strlen.c \
	ft_strchr.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putchar_fd.c \

OBJECTS := $(SOURCES:%.c=%.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
