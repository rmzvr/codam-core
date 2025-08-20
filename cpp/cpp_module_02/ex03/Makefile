NAME := ex03

SOURCES := Fixed.cpp Point.cpp bsp.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPV := -std=c++11
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
