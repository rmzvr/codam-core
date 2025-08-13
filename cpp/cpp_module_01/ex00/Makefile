NAME := BraiiiiiiinnnzzzZ

SOURCES := Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPV := -std=c++20
CPPFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(CPPV) $(OBJECTS) -o $@

%.o: %.cpp
	c++ $(CPPFLAGS) $(CPPV) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
