NAME := philo

SOURCES_PATH = sources/
OBJECTS_PATH = objects/

SRCS := \
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
	death_checkers.c \
	initialization_utils.c \

OBJS := $(SRCS:.c=.o)

SOURCES	= $(addprefix $(SOURCES_PATH), $(SRCS))
OBJECTS	= $(addprefix $(OBJECTS_PATH), $(OBJS))

CC := cc
FLAGS := -Wall -Wextra -Werror -pthread

all: $(NAME)

$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(OBJECTS_PATH)
	$(CC) $(FLAGS) -c $< -o $@ -I ./includes/

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re