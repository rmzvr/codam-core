CLIENT_NAME := client
SERVER_NAME := server

LIBFT_DIR := ./libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a

CLIENT_SOURCES := \
	client.c \

SERVER_SOURCES := \
	server.c \

CLIENT_OBJECTS := $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS := $(SERVER_SOURCES:.c=.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: all

$(CLIENT_NAME): $(LIBFT_NAME) $(CLIENT_OBJECTS)
	$(CC) $(FLAGS) $(CLIENT_OBJECTS) $(LIBFT_NAME) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT_NAME) $(SERVER_OBJECTS)
	$(CC) $(FLAGS) $(SERVER_OBJECTS) $(LIBFT_NAME) -o $(SERVER_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(CLIENT_OBJECTS)
	rm -rf $(SERVER_OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(CLIENT_NAME)
	rm -rf $(SERVER_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
