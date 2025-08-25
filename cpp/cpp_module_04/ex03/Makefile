NAME := ex03

# SOURCES := AMateria.cpp Ice.cpp Cure.cpp main.cpp
# SOURCES := Character.cpp MateriaSource.cpp main.cpp
SOURCES := AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPV := -std=c++20
CPPFLAGS := -Wall -Wextra -Werror -g -O0

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
