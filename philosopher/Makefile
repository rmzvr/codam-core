NAME := philo

SOURCES := \
	philo.c \
	utils.c \
	validation.c \
	error_handling.c \
	handlers.c \
	initialization.c \
	deinitialization.c \
	waiter.c \
	routine.c \
	actions.c \

OBJECTS := $(SOURCES:.c=.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -lpthread

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
