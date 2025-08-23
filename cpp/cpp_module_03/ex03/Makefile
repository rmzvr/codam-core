NAME := ex03

SOURCES := ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPV := -std=c++20
CPPFLAGS := -Wall -Wextra -Werror -Wshadow -g -O0

# -Wshadow -Wno-shadow

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
